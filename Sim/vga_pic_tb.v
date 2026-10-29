`timescale 1ns/1ps

module vga_pic_tb;
    reg        vga_clk;
    reg        sys_rst_n;
    reg  [9:0] pix_x;
    reg  [9:0] pix_y;
    wire [15:0] pix_data;

    vga_pic dut (
        .vga_clk  (vga_clk),
        .sys_rst_n(sys_rst_n),
        .pix_x    (pix_x),
        .pix_y    (pix_y),
        .pix_data (pix_data)
    );

    always #20 vga_clk = ~vga_clk; // 25 MHz

    task check_pixel;
        input integer x;
        input integer y;
        input [15:0] expected;
        begin
            pix_x = x;
            pix_y = y;
            @(posedge vga_clk);
            #1;
            if (pix_data !== expected)
                $display("FAIL: (%0d,%0d) expected %h got %h", x, y, expected, pix_data);
            else
                $display("PASS: (%0d,%0d) = %h", x, y, pix_data);
        end
    endtask

    initial begin
        $dumpfile("vga_pic.vcd");
        $dumpvars(0, vga_pic_tb);
        vga_clk = 1'b0;
        sys_rst_n = 1'b0;
        pix_x = 10'd0;
        pix_y = 10'd0;
        #100;
        if (pix_data !== 16'h0000)
            $display("FAIL: pixel generator is not black during reset");
        sys_rst_n = 1'b1;

        check_pixel(144,     208, 16'hffff);
        check_pixel(144 + 4*8, 208, 16'h0000);
        check_pixel(240, 208, 16'hffff);
        check_pixel(336, 208, 16'h0000);
        check_pixel(432, 208, 16'hffff);
        check_pixel(100, 100, 16'h0000);

        $display("vga_pic_tb completed");
        $finish;
    end
endmodule
