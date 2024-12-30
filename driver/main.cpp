#include <pigpio.h>
#include "driver.cpp"

class RPIHwIface : public HwIface {
    static constexpr int PC_CLK_PIN = 4;
    static constexpr int PC_VALID_PIN = 17;
    static constexpr int PC_DATA_PIN = 27;
    
    static constexpr int FPGA_VALID_PIN = 22;
    static constexpr int FPGA_DATA_PIN = 5;

public:
    RPIHwIface() {
        gpioInitialise();
        gpioSetMode(PC_CLK_PIN, PI_OUTPUT);
        gpioSetMode(PC_VALID_PIN, PI_OUTPUT);
        gpioSetMode(PC_DATA_PIN, PI_OUTPUT);

        gpioSetMode(FPGA_VALID_PIN, PI_INPUT);
        gpioSetMode(FPGA_DATA_PIN, PI_INPUT);
    }

    ~RPIHwIface() {
        gpioTerminate();
    }

    void set_pc_data(int val) {
        gpioWrite(PC_DATA_PIN, val);
    }
    
    void set_pc_valid(int val) {
        gpioWrite(PC_VALID_PIN, val);
    }
    
    void set_pc_clk(int val) {
        gpioWrite(PC_CLK_PIN, val);
    }

    int get_fpga_valid() {
        return gpioRead(FPGA_VALID_PIN);
    }

    int get_fpga_data() {
        return gpioRead(FPGA_DATA_PIN);
    }
};

int main() {
    RPIHwIface hwif;
    OkAndDriver driver(hwif);
    driver.init_driver();

    uint16_t res = driver.okand(65535, 60303);
    printf("%d\n", res);
    return 0;
}
