`default_nettype none
// Empty top module

module top (
  // I/O ports
  input  logic hz100, reset,
  input  logic [20:0] pb,
  output logic [7:0] left, right,
         ss7, ss6, ss5, ss4, ss3, ss2, ss1, ss0,
  output logic red, green, blue,

  // UART ports
  output logic [7:0] txdata,
  input  logic [7:0] rxdata,
  output logic txclk, rxclk,
  input  logic txready, rxready
);
  logic [7:0] rc_clk;
  logic [3:0] temp1;
  logic [3:0] tmep2;
  logic [3:0] dummy1;
  logic [3:0] dummy2;
  logic temp;
  tff t1(.clk(pb[3]), .rst(pb[19]), .T(pb[1]), .Q(ss7[7]));
  tff t2(.clk(pb[3]), .rst(pb[19]), .T(pb[0]), .Q(ss4[7]));
  ring r1(.clk(hz100), .rst(pb[19]), .en(|(pb[2:0])), .Q(rc_clk));
  decimal d1(.clk(rc_clk), .rst(pb[19]), .en(ss7[7]), .Q(temp1));
  decimal d2(.clk(rc_clk), .rst(pb[19]), .en(ss4[7]), .Q(temp2));
  ssdec s1(.in(temp1), .enable(1), .out(ss7[6:0]));
  ssdec s2(.in(temp2), .enable(1), .out(ss5[6:0]));
  bcdadd1 b1(.a(temp1), .b(temp2), .cin(1'b0), .s(dummy1), .cout(temp));
  assign dummy2 = {3'b0,temp};
  ssdec s3(.in(dummy1), .enable(1), .out(ss0[6:0]));
  ssdec s4(.in(dummy2), .enable(1), .out(ss1[6:0]));
  
  // Your code goes here...
  
endmodule
module ssdec(
  input logic [3:0] in,
  input logic enable,
  output logic [6:0] out
);

  logic [6:0] SEG7 [15:0];

  assign SEG7[4'h0] = 7'b0111111;
  assign SEG7[4'h1] = 7'b0000110;
  assign SEG7[4'h2] = 7'b1011011;
  assign SEG7[4'h3] = 7'b1001111;
  assign SEG7[4'h4] = 7'b1100110;
  assign SEG7[4'h5] = 7'b1101101;
  assign SEG7[4'h6] = 7'b1111101;
  assign SEG7[4'h7] = 7'b0000111;
  assign SEG7[4'h8] = 7'b1111111;
  assign SEG7[4'h9] = 7'b1100111;
  assign SEG7[4'ha] = 7'b1110111;
  assign SEG7[4'hb] = 7'b1111100;
  assign SEG7[4'hc] = 7'b0111001;
  assign SEG7[4'hd] = 7'b1011110;
  assign SEG7[4'he] = 7'b1111001;
  assign SEG7[4'hf] = 7'b1110001;

  assign out[6:0] = enable ? SEG7[in] : 0;
endmodule
// Add more modules down here...
module tff(input logic clk, input logic rst, input logic T, output logic Q);
  always_ff @(posedge clk, posedge rst ) begin
    if(rst)
      Q <= 1'b0;
    else if(T)
      Q <= ~Q;
  end
endmodule

module ring(input logic clk, input logic rst, input logic en, output logic[7:0]Q);
  logic [7:0]next_Q;
  always_ff @(posedge clk, posedge rst)
    if(rst)
      Q <= 8'b00000001;
    else if(en)
      Q <= next_Q;
    else
      Q <= Q;

  always_comb begin 
    next_Q = Q << 1;
    if(Q[7] == 1'b1)
       next_Q = 8'b00000001;
  end  
endmodule

module decimal(input logic clk, input logic rst, input logic en, output logic[3:0]Q);
  logic [3:0]next_Q;
  always_ff @(posedge clk, posedge rst)
    if(rst)
      Q <= 4'd0;
    else if(en)
      Q <= next_Q;
  
  always_comb begin
    next_Q = Q + 1;
    if(Q == 4'd9)
      next_Q = 4'd0;
  end
endmodule

module bcdadd1(input logic[3:0]a, input logic[3:0] b, input logic cin, output logic[3:0] s, output logic cout);
  logic [3:0]temp;
  logic [4:0]temp1;
  assign temp1 = a + b + {4'b0,cin};
  assign temp = a + b + {3'b0,cin};
  always_comb
    if(temp1 > 5'd15)begin
      s = temp + 4'd6;
      cout = 1;
    end
    else if(temp > 4'd9)begin
      cout = 1;
      s = temp + 4'd6;
    end
    else begin
      cout = 0;
      s = temp;
    end
endmodule