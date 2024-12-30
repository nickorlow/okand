#include "inttypes.h"
#include "stdio.h"
#include "stdlib.h"
#include <mutex>
#include <deque>
#include <thread>
#include <condition_variable>
#include <unistd.h>

class HwIface {
public:
    virtual ~HwIface(){}
    virtual void set_pc_data(int) = 0;
    virtual void set_pc_valid(int) = 0;
    virtual void set_pc_clk(int) = 0;
    virtual void set_pc_rst(int) = 0;
    virtual int get_fpga_valid() = 0;
    virtual int get_fpga_data() = 0;
    virtual void cleanup() = 0;
};

class QueueRequest {
public:
    uint16_t op_a;
    uint16_t op_b;
    uint16_t *res_ptr;
    bool *wb;
    std::condition_variable *cv;
    std::mutex *mtx;
};

class OkAndDriver {
    std::deque<QueueRequest> request_queue;
    std::mutex queue_mtx;
    class HwIface &_hw_if;
        
    uint16_t input_cnt;
    uint16_t res_cnt;
    uint16_t result;
    
    QueueRequest uiqr;
    QueueRequest *iqr;
    
    QueueRequest uoqr;
    QueueRequest *oqr;

	int compute_delay_cycles = 0;

    int error_counter_ui = 0;
    int error_counter_uo = 0;

public:
    OkAndDriver(class HwIface &hw_if) :_hw_if (hw_if) {}
    
    void init_driver() {
        std::thread t1(&OkAndDriver::dev_loop, this);
        t1.detach();
    }

    void reset_fpga() {
        // Zero out 
        _hw_if.set_pc_clk(0);
        _hw_if.set_pc_data(0);
        _hw_if.set_pc_valid(0);
		usleep(1);

        // Cycle with RST on
        _hw_if.set_pc_rst(1);
        _hw_if.set_pc_clk(1);
		usleep(1);

        // Re-zero
        _hw_if.set_pc_rst(0);
        _hw_if.set_pc_clk(0);
		usleep(1);

        // Reset state on our end
		input_cnt = 0;
		res_cnt = 0;
		result = 0;
		compute_delay_cycles = 0;

        if (iqr != nullptr) {
            std::lock_guard<std::mutex> lock(queue_mtx);
            request_queue.push_front(uiqr);
        }

        if (oqr != nullptr) {
		    uiqr = uoqr;
		    iqr = &uiqr;
		    oqr = nullptr;
        } else {
            iqr = nullptr;
        }
    }
    
    void dev_loop() {
        reset_fpga();

        while(true) {
            {
                std::lock_guard<std::mutex> lock(queue_mtx);
                if (iqr == nullptr && !request_queue.empty() && input_cnt == 0) {
                    uiqr = request_queue.front();
                    iqr = &uiqr;
                    request_queue.pop_front();
                }
            }
    
            if (iqr != nullptr) {
                _hw_if.set_pc_valid(1);
    
                if (input_cnt <= 15) {
                    _hw_if.set_pc_data((iqr->op_a >> (input_cnt)) & 1);
                } else {
                    _hw_if.set_pc_data((iqr->op_b >> (input_cnt-16)) & 1);
                }
    
                input_cnt++;
    
                if (input_cnt == 32) {
                    input_cnt = 0;
                    uoqr = uiqr;
                    oqr = &uoqr;
                    iqr = nullptr;
		            compute_delay_cycles = 0;
                }
            } else {
                _hw_if.set_pc_valid(0);
            }
    
            _hw_if.set_pc_clk(1);
    
            if (_hw_if.get_fpga_valid()) {
		        if (oqr == nullptr) {
                    reset_fpga();
                    error_counter_uo++;
		        	continue;
		        }

                result = result | (_hw_if.get_fpga_data() << res_cnt);
                res_cnt++;
    
                if (res_cnt == 16 && oqr != nullptr) {
                    {
                        std::lock_guard<std::mutex> lock(*oqr->mtx);
                        *oqr->wb = true;
                        *oqr->res_ptr = result;
                    }
                    res_cnt = 0;
                    result = 0;
                    oqr->cv->notify_one();
                    oqr = nullptr;
                } else if (res_cnt == 16) {
                    res_cnt = 0;
                    result = 0;
                }
            } else {
		        if (oqr != nullptr) {
			        if (compute_delay_cycles == 2) {
                        reset_fpga();
                        error_counter_ui++;
                        continue;
                    } else {
                        compute_delay_cycles += 1;
                    }
		        }
                res_cnt = 0;
                result = 0;
            }
    
            _hw_if.set_pc_clk(0);
        }
    }
    
    
    uint16_t okand(uint16_t a, uint16_t b) {
        uint16_t res = 0;
        bool wb_done = false;

        std::condition_variable cv;
        std::mutex mtx;
    
        struct QueueRequest qr;
        qr.res_ptr = &res;
        qr.op_a = a;
        qr.op_b = b;
        qr.cv = &cv;
        qr.wb = &wb_done;
        qr.mtx = &mtx;
    
        {
            std::lock_guard<std::mutex> lock(queue_mtx);
            request_queue.push_back(qr);
        }
    
        std::unique_lock<std::mutex> lk(mtx);
        qr.cv->wait(lk, [&qr] {return *qr.wb;});
    
        return res;
    }

    void cleanup() {
        _hw_if.cleanup();
    }
};
