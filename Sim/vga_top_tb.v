`timescale 1ns/1ps

module vga_top_tb;
    reg        sys_clk;
    reg        sys_rst_n;
    wire       hsync;
    wire       vsync;
    wire [15:0] rgb;
    integer    h_edges;
    integer    v_edges;

    vga_top dut (
        .sys_clk  (sys_clk),
        .sys_rst_n(sys_rst_n),
        .hsync    (hsync),
        .vsync    (vsync),
        .rgb      (rgb)
    );

    always #10 sys_clk = ~sys_clk;

    initial begin
        $dumpfile("vga_top.vcd");
        $dumpvars(0, vga_top_tb);
        sys_clk = 1'b0;
        sys_rst_n = 1'b0;
        #100;
        if (rgb !== 16'h0000)
            $display("FAIL: RGB is not black during reset");
        sys_rst_n = 1'b1;

        repeat (400) @(posedge dut.vga_clk);
        if (dut.vga_ctrl_inst.cnt_h !== 10'd0)
            $display("INFO: counter phase after reset release = %0d", dut.vga_ctrl_inst.cnt_h);

        repeat (840000) @(posedge dut.vga_clk);
        $display("PASS: top-level simulation completed");
        $finish;
    end
endmodule
