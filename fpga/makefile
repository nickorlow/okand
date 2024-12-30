build:
	verilator --cc --exe --build --timing -j 0 --top-module okand *.sv testbench.cpp -CFLAGS "-g -O0"

run: build
	obj_dir/Vokand
