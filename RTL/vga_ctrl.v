`timescale 1ns/1ps

module vga_ctrl (
    input  wire        vga_clk,
    input  wire        sys_rst_n,
    input  wire [15:0] pix_data,
    output wire [9:0]  pix_x,
    output wire [9:0]  pix_y,
    output wire        hsync,
    output wire        vsync,
    output wire [15:0] rgb
);
    localparam integer H_SYNC  = 96;
    localparam integer H_BACK  = 40;
    localparam integer H_LEFT  = 8;
    localparam integer H_VALID = 640;
    localparam integer H_RIGHT = 8;
    localparam integer H_FRONT = 8;
    localparam integer H_TOTAL = H_SYNC + H_BACK + H_LEFT + H_VALID + H_RIGHT + H_FRONT;

    localparam integer V_SYNC  = 2;
    localparam integer V_BACK  = 25;
    localparam integer V_TOP   = 8;
    localparam integer V_VALID = 480;
    localparam integer V_BOTTOM = 8;
    localparam integer V_FRONT = 2;
    localparam integer V_TOTAL = V_SYNC + V_BACK + V_TOP + V_VALID + V_BOTTOM + V_FRONT;

    reg [9:0] cnt_h;
    reg [9:0] cnt_v;
    wire rgb_valid;
    wire pix_data_req;

    assign hsync = (cnt_h < H_SYNC) ? 1'b1 : 1'b0;
    assign vsync = (cnt_v < V_SYNC) ? 1'b1 : 1'b0;

    assign rgb_valid =
        (cnt_h >= H_SYNC + H_BACK + H_LEFT) &&
        (cnt_h <  H_SYNC + H_BACK + H_LEFT + H_VALID) &&
        (cnt_v >= V_SYNC + V_BACK + V_TOP) &&
        (cnt_v <  V_SYNC + V_BACK + V_TOP + V_VALID);

    assign pix_data_req =
        (cnt_h >= H_SYNC + H_BACK + H_LEFT - 1) &&
        (cnt_h <  H_SYNC + H_BACK + H_LEFT + H_VALID - 1) &&
        (cnt_v >= V_SYNC + V_BACK + V_TOP) &&
        (cnt_v <  V_SYNC + V_BACK + V_TOP + V_VALID);

    assign pix_x = pix_data_req
                 ? cnt_h - (H_SYNC + H_BACK + H_LEFT - 1)
                 : 10'h3ff;
    assign pix_y = pix_data_req
                 ? cnt_v - (V_SYNC + V_BACK + V_TOP)
                 : 10'h3ff;
    
    assign rgb = (sys_rst_n && rgb_valid) ? pix_data : 16'h0000;
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            cnt_h <= 10'd0;
            cnt_v <= 10'd0;
        end else begin
            if (cnt_h == H_TOTAL - 1) begin
                cnt_h <= 10'd0;
                if (cnt_v == V_TOTAL - 1)
                    cnt_v <= 10'd0;
                else
                    cnt_v <= cnt_v + 10'd1;
            end else begin
                cnt_h <= cnt_h + 10'd1;
            end
        end
    end
endmodule
