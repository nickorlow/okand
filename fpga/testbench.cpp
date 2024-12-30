#include "inttypes.h"
#include "stdlib.h"
#include "./driver.cpp"


int main(int argc, char** argv) {
    init_driver();
    uint16_t res = okand(65535, 65535);

    printf("and res %d\n", res);

    return 0;
}


