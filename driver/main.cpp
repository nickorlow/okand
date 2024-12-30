#include <pigpio.h>
#include "driver.cpp"
#include <unistd.h>
#include <signal.h>
#include <mutex>

void signal_handler(int signal) {
	switch(signal) {
		case SIGINT:
		case SIGTERM:
		case SIGSEGV:
			gpioTerminate();
			break;
		default: break;
	}
}

class RPIHwIface : public HwIface {
    static constexpr int PC_CLK_PIN = 4;
    static constexpr int PC_VALID_PIN = 17;
    static constexpr int PC_DATA_PIN = 27;
    static constexpr int PC_RST_PIN = 26;
    
    static constexpr int FPGA_VALID_PIN = 22;
    static constexpr int FPGA_DATA_PIN = 5;

    std::mutex mtx;

public:
    RPIHwIface() {
        std::lock_guard<std::mutex> lg(mtx);
        gpioCfgSetInternals(1<<10);
        gpioInitialise();
        gpioSetMode(PC_CLK_PIN, PI_OUTPUT);
        gpioSetMode(PC_VALID_PIN, PI_OUTPUT);
        gpioSetMode(PC_DATA_PIN, PI_OUTPUT);
        gpioSetMode(PC_RST_PIN, PI_OUTPUT);

        gpioSetMode(FPGA_VALID_PIN, PI_INPUT);
        gpioSetMode(FPGA_DATA_PIN, PI_INPUT);
    }

    ~RPIHwIface() {
	cleanup();
    }

    void set_pc_data(int val) {
        std::lock_guard<std::mutex> lg(mtx);
        gpioWrite(PC_DATA_PIN, val);
    }

    void set_pc_rst(int val) {
        std::lock_guard<std::mutex> lg(mtx);
	gpioWrite(PC_RST_PIN, val);
    }
    
    void set_pc_valid(int val) {
        std::lock_guard<std::mutex> lg(mtx);
        gpioWrite(PC_VALID_PIN, val);
    }
    
    void set_pc_clk(int val) {
        std::lock_guard<std::mutex> lg(mtx);
	usleep(250 * 1000);
        gpioWrite(PC_CLK_PIN, val);
    }

    int get_fpga_valid() {
        std::lock_guard<std::mutex> lg(mtx);
        return gpioRead(FPGA_VALID_PIN);
    }

    int get_fpga_data() {
        std::lock_guard<std::mutex> lg(mtx);
        return gpioRead(FPGA_DATA_PIN);
    }

    void cleanup() {
        std::lock_guard<std::mutex> lg(mtx);
        gpioTerminate();
    }
};

int main() {
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGSEGV, signal_handler);

    RPIHwIface hwif;
    OkAndDriver driver(hwif);
    driver.init_driver();

    for(uint16_t i = 0;;i++) {
        printf("i %d\n", i);
        for(uint16_t j = 0;;j++) {
            uint16_t res = driver.okand(i,j);
            if ((i&j) != res) {
                printf("%d & %d = %d (exp %d)\n", i, j, res, i&j);
                return 1;
            }
            if (j == 65535) break;
        }
        if (i == 65535) break;
    }

    driver.cleanup();
    return 0;
}
