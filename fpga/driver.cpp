#include "verilated.h"
#include "Vokand.h"
#include "inttypes.h"
#include "stdio.h"
#include "stdlib.h"
#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>

class queue_request {
public:
    uint16_t op_a;
    uint16_t op_b;
    uint16_t *res_ptr;
    std::condition_variable *cv;
};

std::queue<queue_request> request_queue;
std::mutex queue_mtx;

void dev_loop() {
    VerilatedContext *contextp = new VerilatedContext;
    Vokand *dut = new Vokand{contextp}; 

    uint16_t input_cnt = 0;
    uint16_t res_cnt = 0;
    uint16_t result = 0;;


    struct queue_request uiqr;
    struct queue_request *iqr = nullptr;

    struct queue_request uoqr;
    struct queue_request *oqr = nullptr;

    while(true) {

        {
            std::lock_guard<std::mutex> lock(queue_mtx);
            if (iqr == nullptr && !request_queue.empty()) {
                uiqr = request_queue.front();
                request_queue.pop();
                iqr = &uiqr;
                printf("New input on queue\n");
            }
        }

        if (iqr != nullptr) {
            dut->pc_valid = 1;

            if (input_cnt <= 15) {
                dut->pc_data = iqr->op_a >> (input_cnt);
                dut->pc_data &=1;
            } else {
                dut->pc_data = iqr->op_b >> (input_cnt - 16);
                dut->pc_data &=1;
            }
            printf("data: %d  ic: %d\n", dut->pc_data, input_cnt);

            input_cnt++;

            if (input_cnt == 32) {
                input_cnt = 0;

                uoqr = uiqr;
                oqr = &uoqr;

                iqr = nullptr;
                printf("iqr -> oqr\n");
            }
        } else {
            dut->pc_valid = 0;
        }

        dut->pc_clk = 1;
        dut->eval();


        dut->pc_clk = 0;
        dut->eval();
    }
}

void init_driver() {
    std::thread t1(dev_loop);
    t1.detach();
}

uint16_t okand(uint16_t a, uint16_t b) {
    uint16_t res = 0;
    std::condition_variable cv;

    struct queue_request qr;

    qr.res_ptr = &res;
    qr.op_a = a;
    qr.op_b = b;
    qr.cv = &cv;

    {
        std::lock_guard<std::mutex> lock(queue_mtx);
        request_queue.push(qr);
    }

    std::mutex mtx;
    std::unique_lock<std::mutex> lk(mtx);
    qr.cv->wait(lk);

    return res;
}
