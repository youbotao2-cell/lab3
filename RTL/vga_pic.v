`timescale 1ns/1ps

module vga_pic (
    input  wire        vga_clk,
    input  wire        sys_rst_n,
    input  wire [9:0]  pix_x,
    input  wire [9:0]  pix_y,
    output reg  [15:0] pix_data
);
    localparam [15:0] BLACK = 16'h0000;
    localparam [15:0] WHITE = 16'hffff;

    localparam integer SCALE = 8;
    localparam integer CHAR_W = 8 * SCALE;
    localparam integer CHAR_H = 8 * SCALE;
    localparam integer CHAR_Y = 208;
    localparam integer M_X = 144;
    localparam integer U_X = 240;
    localparam integer S_X = 336;
    localparam integer T_X = 432;

    reg [1:0] char_id;
    reg [2:0] char_x;
    reg [2:0] char_y;
    reg [7:0] row_bits;
    reg       pixel_on;

    always @* begin
        char_id  = 2'd0;
        char_x   = 3'd0;
        char_y   = 3'd0;
        row_bits = 8'b0;
        pixel_on = 1'b0;

        if ((pix_y >= CHAR_Y) && (pix_y < CHAR_Y + CHAR_H)) begin
            char_y = (pix_y - CHAR_Y) / SCALE;

            if ((pix_x >= M_X) && (pix_x < M_X + CHAR_W)) begin
                char_id = 2'd0;
                char_x = (pix_x - M_X) / SCALE;
            end else if ((pix_x >= U_X) && (pix_x < U_X + CHAR_W)) begin
                char_id = 2'd1;
                char_x = (pix_x - U_X) / SCALE;
            end else if ((pix_x >= S_X) && (pix_x < S_X + CHAR_W)) begin
                char_id = 2'd2;
                char_x = (pix_x - S_X) / SCALE;
            end else if ((pix_x >= T_X) && (pix_x < T_X + CHAR_W)) begin
                char_id = 2'd3;
                char_x = (pix_x - T_X) / SCALE;
            end

            case (char_id)
                2'd0: begin
                    case (char_y)
                        3'd0: row_bits = 8'b1100_0011;
                        3'd1: row_bits = 8'b1110_0111;
                        3'd2: row_bits = 8'b1111_1111;
                        3'd3: row_bits = 8'b1101_1011;
                        3'd4: row_bits = 8'b1100_0011;
                        3'd5: row_bits = 8'b1100_0011;
                        3'd6: row_bits = 8'b1100_0011;
                        3'd7: row_bits = 8'b1100_0011;
                    endcase
                end
                2'd1: begin
                    case (char_y)
                        3'd0: row_bits = 8'b1100_0011;
                        3'd1: row_bits = 8'b1100_0011;
                        3'd2: row_bits = 8'b1100_0011;
                        3'd3: row_bits = 8'b1100_0011;
                        3'd4: row_bits = 8'b1100_0011;
                        3'd5: row_bits = 8'b1100_0011;
                        3'd6: row_bits = 8'b1110_0111;
                        3'd7: row_bits = 8'b0011_1100;
                    endcase
                end
                2'd2: begin
                    case (char_y)
                        3'd0: row_bits = 8'b0111_1110;
                        3'd1: row_bits = 8'b1100_0011;
                        3'd2: row_bits = 8'b1100_0000;
                        3'd3: row_bits = 8'b0111_1110;
                        3'd4: row_bits = 8'b0000_0011;
                        3'd5: row_bits = 8'b0000_0011;
                        3'd6: row_bits = 8'b1100_0011;
                        3'd7: row_bits = 8'b0111_1110;
                    endcase
                end
                2'd3: begin
                    case (char_y)
                        3'd0: row_bits = 8'b1111_1111;
                        3'd1: row_bits = 8'b0001_1000;
                        3'd2: row_bits = 8'b0001_1000;
                        3'd3: row_bits = 8'b0001_1000;
                        3'd4: row_bits = 8'b0001_1000;
                        3'd5: row_bits = 8'b0001_1000;
                        3'd6: row_bits = 8'b0001_1000;
                        3'd7: row_bits = 8'b0001_1000;
                    endcase
                end
            endcase

            if (((pix_x >= M_X) && (pix_x < M_X + CHAR_W)) ||
                ((pix_x >= U_X) && (pix_x < U_X + CHAR_W)) ||
                ((pix_x >= S_X) && (pix_x < S_X + CHAR_W)) ||
                ((pix_x >= T_X) && (pix_x < T_X + CHAR_W))) begin
                pixel_on = row_bits[7 - char_x];
            end
        end
    end

    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            pix_data <= BLACK;
        else
            pix_data <= pixel_on ? WHITE : BLACK;
    end
endmodule
