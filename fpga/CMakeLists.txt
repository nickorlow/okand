cmake_minimum_required(VERSION 3.12)
project(ok_and)

# Setup testbench target
find_package(verilator REQUIRED)
add_executable(okand_tb testbench.cpp)
verilate(
    okand_tb
    SOURCES okand.sv 
)
