module okand (
    input wire pc_clk,
    input wire pc_data,
    input wire pc_valid,
    output logic fpga_data,
    output logic fpga_valid
    );

    logic [15:0] op_1;
    logic [15:0] op_2;
    logic [4:0] op_idx;

    logic [15:0] result;
    logic [3:0] res_idx;

    logic do_compute;
    logic do_output;

    always_ff @(posedge pc_clk) begin
        if (pc_valid) begin
            if (op_idx[4]) begin
               op_2[op_idx[3:0]] <= pc_data; 
            end else begin
               op_1[op_idx[3:0]] <= pc_data; 
            end

            op_idx <= op_idx + 1;

            if (op_idx == 5'b11111) begin
                do_compute <= 1;
            end else begin
                do_compute <= 0;
            end
        end

        $display("%b %b %d", op_1, op_2, op_idx);
            
        if (do_compute) begin
            result <= op_1 & op_2; 
            do_compute <= 0;
            do_output <= 1;
        end

        if (do_output) begin
            fpga_valid <= 1;
            fpga_data <= result[res_idx];
            res_idx <= res_idx + 1;
            if (res_idx == 4'b1111) begin
                do_output <= 0;
            end
        end else begin
            fpga_valid <= 0;
        end
    end
endmodule
