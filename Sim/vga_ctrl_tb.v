`timescale 1ns/1ps

module vga_ctrl_tb;
    reg        vga_clk;
    reg        sys_rst_n;
    reg  [15:0] pix_data;
    wire [9:0] pix_x;
    wire [9:0] pix_y;
    wire       hsync;
    wire       vsync;
    wire [15:0] rgb;

    vga_ctrl dut (
        .vga_clk  (vga_clk),
        .sys_rst_n(sys_rst_n),
        .pix_data (pix_data),
        .pix_x    (pix_x),
        .pix_y    (pix_y),
        .hsync    (hsync),
        .vsync    (vsync),
        .rgb      (rgb)
    );

    always #20 vga_clk = ~vga_clk; // 25 MHz

    initial begin
        $dumpfile("vga_ctrl.vcd");
        $dumpvars(0, vga_ctrl_tb);
        vga_clk = 1'b0;
        sys_rst_n = 1'b0;
        pix_data = 16'hffff;
        #100;
        sys_rst_n = 1'b1;

        repeat (95) @(posedge vga_clk);
        #1;
        if (!hsync)
            $display("FAIL: horizontal sync ended too early");
        @(posedge vga_clk);
        #1;
        if (hsync)
            $display("FAIL: horizontal sync is wider than 96 clocks");

        repeat (704) @(posedge vga_clk);
        #1;
        if (dut.cnt_h !== 10'd0)
            $display("FAIL: horizontal counter did not wrap at 800");

        repeat (34 * 800) @(posedge vga_clk);
        #1;
        if (dut.cnt_v !== 10'd35)
            $display("FAIL: vertical counter did not reach active-video start");

        $display("vga_ctrl_tb completed: x=%0d y=%0d rgb=%h", pix_x, pix_y, rgb);
        $finish;
    end
endmodule
