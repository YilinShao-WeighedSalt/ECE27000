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

 lunarlander ll (
    .hz100(hz100), .reset(reset), .in(pb[19:0]), 
    .red(red), .green(green),                       // for crashed/landed
    .ss0(ss0), .ss1(ss1), .ss2(ss2), .ss3(ss3),     // for values
    .ss5(ss5), .ss6(ss6), .ss7(ss7)                 // for display message
);
endmodule
module clock_psc(input logic clk, input logic rst, input logic [7:0]lim, output logic hzX);
  logic [7:0]ct, nextct;
  logic nexthzX;

  always_ff @(posedge clk, posedge rst)
  begin
    if(rst)
      begin
        hzX <= 0;
        ct <= 0;
      end
    else 
      begin
        hzX <= nexthzX;
        ct <= nextct;
      end
  end

  always_comb 
  begin
      nexthzX = hzX;
      nextct = ct;
      if(lim == 0)
        nexthzX = ~clk;
      else if(ct == lim)
        begin
          nexthzX = ~hzX;
          nextct = 0;
        end
      else 
        begin
          nextct = ct + 1;
          nexthzX = hzX;
        end
  end
endmodule
module keysync(input logic clk, input logic rst, input logic [19:0]keyin, output logic [4:0]keyout, output logic keyclk);
  assign keyout[0] = |{keyin[1], keyin[3], keyin[5], keyin[7], keyin[9], keyin[11], keyin[13], keyin[15], keyin[17], keyin[19]};
  assign keyout[1] = |{keyin[2], keyin[3], keyin[6], keyin[7], keyin[10], keyin[11], keyin[14], keyin[15], keyin[18], keyin[19]};
  assign keyout[2] = |{keyin[4], keyin[5], keyin[6], keyin[7], keyin[12], keyin[13], keyin[14], keyin[15]};
  assign keyout[3] = |keyin[15:8];
  assign keyout[4] = |keyin[19:16];
  
  logic [1:0] delay;
  always_ff @(posedge clk, posedge rst) begin
    if (rst) begin
      delay <= 0;
    end else begin
      delay <= (delay << 1) | {1'b0,|keyin};
    end
  end

  assign keyclk = delay[1];
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
module fa(input logic a, input logic b, input logic ci, output logic s, output logic co);
  assign s = a ^ b ^ ci;
  assign co = (a & b) | (a & ci) | (b & ci);
endmodule

module fa4(input logic[3:0]a, input logic[3:0]b, input logic ci, output logic[3:0]s, output logic co);
  logic c1,c2,c3;

  fa fa0(.a(a[0]), .b(b[0]), .ci(ci), .s(s[0]), .co(c1));
  fa fa1(.a(a[1]), .b(b[1]), .ci(c1), .s(s[1]), .co(c2));
  fa fa2(.a(a[2]), .b(b[2]), .ci(c2), .s(s[2]), .co(c3));
  fa fa3(.a(a[3]), .b(b[3]), .ci(c3), .s(s[3]), .co(co));
endmodule

module bcdadd1(input logic[3:0]a, input logic[3:0]b, input logic ci, output logic co, output logic[3:0]s);
  logic [3:0]sum;
  logic z4;
  logic cout;
  fa4 fa_4(.a(a), .b(b), .ci(ci), .co(z4), .s(sum));
  assign cout = z4 | (sum[3] & sum[2]) | (sum[3] & sum[1]);
  assign co = cout;
  // fa4 fa_4_1(.a({4'b0 | (cout << 2) | (cout << 1)}), .b(sum), .ci(1'b0), .co(cout), .s(s));
  
  fa4 fax(.a({1'b0, cout, cout, 1'b0}), .b(sum), .ci(1'b0), .co(), .s(s));
endmodule

module bcdadd4(input logic[15:0]a, input logic[15:0]b, input logic ci, output logic[15:0]s, output logic co);
  logic c1,c2,c3;
  bcdadd1 bd0(.a(a[3:0]), .b(b[3:0]), .ci(ci), .s(s[3:0]), .co(c1));
  bcdadd1 bd1(.a(a[7:4]), .b(b[7:4]), .ci(c1), .s(s[7:4]), .co(c2));
  bcdadd1 bd2(.a(a[11:8]), .b(b[11:8]), .ci(c2), .s(s[11:8]), .co(c3));
  bcdadd1 bd3(.a(a[15:12]), .b(b[15:12]), .ci(c3), .s(s[15:12]), .co(co));
endmodule

module bcd9comp1(input logic[3:0]in, output logic[3:0]out);
always_comb
  case (in)
  4'b0000: out = 4'b1001;
  4'b0001: out = 4'b1000;
  4'b0010: out = 4'b0111;
  4'b0011: out = 4'b0110;
  4'b0100: out = 4'b0101; 
  4'b0101: out = 4'b0100;
  4'b0110: out = 4'b0011;
  4'b0111: out = 4'b0010;
  4'b1000: out = 4'b0001;
  4'b1001: out = 4'b0000;
  default: out = 4'b0000; // used for inputs > 9
endcase
endmodule

module bcdaddsub4(input logic[15:0]a, input logic[15:0]b, input logic op, output logic[15:0]s);
  logic [3:0]t0,t1,t2,t3;
  logic [15:0]temp;
  //if op = 1, take the comp of b to t[3:0]
  bcd9comp1 bc0(.in(b[3:0]), .out(t0));
  bcd9comp1 bc1(.in(b[7:4]), .out(t1));
  bcd9comp1 bc2(.in(b[11:8]), .out(t2));
  bcd9comp1 bc3(.in(b[15:12]), .out(t3));

  assign temp[3:0] = op ? t0 : b[3:0];
  assign temp[7:4] = op ? t1 : b[7:4];
  assign temp[11:8] = op ? t2 : b[11:8];
  assign temp[15:12] = op ? t3 : b[15:12];

  bcdadd4 bd(.a(a), .b(temp), .ci(op), .s(s), .co());
  //if op = 0 , add a & b
  //if op = 1, add a & ~b + op;
endmodule

module ll_memory#(
  parameter FUEL=16'h800,
  parameter ALTITUDE=16'h4500,
  parameter VELOCITY=16'h0,
  parameter THRUST=16'h5,
  parameter GRAVITY=16'h5
) (input logic clk, 
   input logic rst, 
   input logic wen, 
   input logic[15:0]alt_n, 
   input logic[15:0]vel_n, 
   input logic[15:0]fuel_n, 
   input logic[15:0]thrust_n, 
   output logic[15:0]alt, 
   output logic[15:0]vel,
   output logic[15:0]fuel,
   output logic[15:0]thrust);
    always_ff @(posedge clk, posedge rst)
      if(rst)begin
        alt <= ALTITUDE;
        vel <= VELOCITY;
        fuel <= FUEL;
        thrust <= THRUST;
      end
      else if(wen)begin
        alt <= alt_n;
        vel <= vel_n;
        fuel <= fuel_n;
        thrust <= thrust_n;
      end
endmodule

module ll_alu #(
  parameter GRAVITY = 16'h5
) (input logic[15:0]alt,
   input logic[15:0]vel,
   input logic[15:0]fuel,
   input logic[15:0]thrust,
   output logic[15:0]alt_n,
   output logic[15:0]vel_n,
   output logic[15:0]fuel_n);

   logic [15:0]alt_c,vel_ci,fuel_c,vel_cf;
   logic [15:0]temp_thrust;

   bcdaddsub4 bd0(.a(alt), .b(vel), .op(0), .s(alt_c));
   bcdaddsub4 bd1(.a(vel), .b(GRAVITY), .op(1), .s(vel_ci));
   assign temp_thrust = (fuel == 0) ? 16'b0 : thrust;
   bcdaddsub4 bd2(.a(vel_ci), .b(temp_thrust), .op(0), .s(vel_cf));
   bcdaddsub4 bd3(.a(fuel), .b(thrust), .op(1), .s(fuel_c));
   
   always_comb begin
    if(((alt_c >> 15) & 16'b1) == 16'b1 || alt_c == 0)begin
      alt_n = 0;
      vel_n = 0;
    end
    else begin
      alt_n = alt_c;
      vel_n = vel_cf;
    end
    if(((fuel_c >> 15) & 16'b1) == 16'b1 || fuel_c == 0)
      fuel_n = 0;
    else
      fuel_n = fuel_c;
   end
endmodule

module ll_control(
  input logic clk,
  input logic rst,
  input logic[15:0]alt,
  input logic[15:0]vel,
  output logic land,
  output logic crash,
  output logic wen
);
logic [15:0]v_a;
logic next_crash,next_land, next_wen;
bcdaddsub4 bd0(.a(alt), .b(vel), .op(1'b0), .s(v_a));

  always_ff @(posedge clk, posedge rst)
    if(rst)begin
      land <= 1'b0;
      crash <= 1'b0;
      wen <= 1'b0;
    end
    else begin
      wen <= next_wen;
      crash <= next_crash;
      land <= next_land;
    end
  always_comb
    if(~(land | crash)) begin
      if(((v_a >> 15) & 16'b1) == 16'b1 || v_a == 0)begin
        // next_wen = 0;
        if(vel < 16'h9970)begin
          next_crash = 1'b1;
          next_land = 1'b0;
          next_wen = 1'b0;
        end
        else begin
          next_land = 1'b1;
          next_crash = 1'b0;
          next_wen = 1'b0;
        end
      end
      else begin
          next_wen = 1'b1;
          next_crash = 1'b0;
          next_land = 1'b0;
        end
    end
    else begin
      next_wen = wen;
      next_crash = crash;
      next_land = land;
      end
endmodule