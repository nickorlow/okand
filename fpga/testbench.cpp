#include "inttypes.h"
#include "stdlib.h"
#include "../driver/driver.cpp"
#include "assert.h"
#include "verilated.h"
#include "Vokand.h"

class VerilogHwIface : public HwIface {
    Vokand *_dut;
    VerilatedContext *_contextp;
public:
    VerilogHwIface() {
        _contextp = new VerilatedContext;
        _dut = new Vokand{_contextp}; 
    }

    void set_pc_data(int val) {
        _dut->pc_data = val;
        _dut->eval();
    }
    
    void set_pc_valid(int val) {
        _dut->pc_valid = val;
        _dut->eval();
    }
    
    void set_pc_clk(int val) {
        _dut->pc_clk = val;
        _dut->eval();
    }
    
    void set_pc_rst(int val) {
        _dut->pc_rst = val;
        _dut->eval();
    }

    int get_fpga_valid() {
        return _dut->fpga_valid;
    }

    int get_fpga_data() {
        return _dut->fpga_data;
    }

    void cleanup() {
        delete _dut;
        delete _contextp;
    }
};

int main(int argc, char** argv) {
    VerilogHwIface hwif;
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

    return 0;
}
