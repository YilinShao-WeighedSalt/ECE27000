`default_nettype none
typedef enum logic [3:0] {
  LS0=0, LS1=1, LS2=2, LS3=3, LS4=4, LS5=5, LS6=6, LS7=7,
  INIT=8, OPEN=9, ALARM=10
} state_t;
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
  logic nhzX;
  clock_psc psc(.clk(hz100), .rst(reset), .lim(8'd49), .hzX(nhzX));

  logic [4:0] keycode;
  logic strobe;
  keysync sk1 (.clk(hz100), .rst(reset), .keyin(pb[19:0]), .keyout(keycode), .keyclk(strobe));

  logic [7:0]seq;

  assign right = seq;
  logic [3:0]curr_state;
  sequence_sr sqe1(.clk(strobe), .rst(reset), .en(~|keycode[4:1] & (curr_state == INIT)), .button(keycode[0]), .seq(seq));

  fsm sm1(.clk(strobe), .rst(reset), .keyout(keycode), .seq(seq), .state(curr_state));
  
  logic [63:0]ssdec;
  assign {ss7,ss6,ss5,ss4,ss3,ss2,ss1,ss0} = ssdec;

  display dp(.hzX(nhzX), .state(curr_state), .ss(ssdec), .red(red), .green(green), .blue(blue));
endmodule
module clock_psc(input logic clk, input logic rst, input logic [7:0]lim, output logic hzX);
  logic [7:0]ct, nextct;
  logic nexthzX;

  always_ff @(posedge clk, posedge rst)begin
    if(rst)begin
        hzX <= 0;
        ct <= 0;
      end
    else begin
        hzX <= nexthzX;
        ct <= nextct;
      end
  end

  always_comb begin
      nexthzX = hzX;
      nextct = ct;
      if(lim == 0)
        nexthzX = ~clk;
      else if(ct == lim)begin
          nexthzX = ~hzX;
          nextct = 0;
        end
      else begin
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
    end 
    else begin
      delay <= (delay << 1) | {1'b0,|keyin};
    end
  end

  assign keyclk = delay[1];
endmodule

module sequence_sr(input logic clk, input logic rst, input logic en, input logic button, output logic [7:0]seq);
  logic [7:0] nextseq;
  // logic [7:0] mask;
  always_ff @(posedge clk, posedge rst)
    begin
      if(rst)
        seq <= 8'b00000000;
      else if(~en)
        seq <= seq;
      else
        seq <= nextseq;
    end
  always_comb
    begin
      nextseq = seq;
      nextseq = nextseq << 1;
      nextseq [0] = button;
    end
endmodule

module fsm(input logic clk, input logic rst, input logic[4:0]keyout, input logic[7:0]seq, output logic[3:0]state);
  state_t lockstate, n_lockstate;
  logic M, R;
  assign state = lockstate;


  assign R = keyout == 5'd16;
  assign M = keyout[0] == seq[~lockstate[2:0]];

  always_ff @(posedge clk, posedge rst)
    begin
      if(rst)
        lockstate <= INIT;
      else
        lockstate <= n_lockstate;
    end
  always_comb
    casez ({lockstate, M, R})
        {INIT, 1'b?, 1'b1}: n_lockstate = LS0;
        {LS0, 1'b1, 1'b0}: n_lockstate = LS1;
        {LS0, 1'b0, 1'b0}: n_lockstate = ALARM;

        {LS1, 1'b1, 1'b0}: n_lockstate = LS2;
        {LS1, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS1, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS2, 1'b1, 1'b0}: n_lockstate = LS3;
        {LS2, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS2, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS3, 1'b1, 1'b0}: n_lockstate = LS4;
        {LS3, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS3, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS4, 1'b1, 1'b0}: n_lockstate = LS5;
        {LS4, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS4, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS5, 1'b1, 1'b0}: n_lockstate = LS6;
        {LS5, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS5, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS6, 1'b1, 1'b0}: n_lockstate = LS7;
        {LS6, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS6, 1'b?, 1'b1}: n_lockstate = LS0;

        {LS7, 1'b1, 1'b0}: n_lockstate = OPEN;
        {LS7, 1'b0, 1'b0}: n_lockstate = ALARM;
        {LS7, 1'b?, 1'b1}: n_lockstate = LS0;

        {OPEN, 1'b?, 1'b1}: n_lockstate = LS0;
        default: n_lockstate = lockstate;
    endcase
endmodule

module display(input logic hzX, input logic[3:0]state, output logic[63:0]ss, output logic red, output logic green, output logic blue);
  logic [63:0]nss;
  always_comb begin
    case(state)
      INIT: 
      begin
        red = 1'b0;
        ss = 64'b0;
        blue = 0;
        green = 0;
      end

      LS0, LS1, LS2, LS3, LS4, LS5, LS6, LS7:
        begin
          ss = 64'b01101101_01111001_00111001_00111110_01010000_01111001 | (64'b1 << (((8-state)*8) - 1));
          // nss = ss;
          // nss[6'd63 - state * 6'd8] = 1'b1;
          // ss = ss | nss;
          blue = 1'b1;
          green = 1'b0;
          red = 1'b0;
        end
      
      OPEN: 
        begin
          ss = 64'b00111111_01110011_01111001_01010100;
          green = 1'b1;
          red = 1'b0;
          blue = 1'b0;
        end
      ALARM: 
        begin
          ss = 64'b00111001_01110111_00111000_00111000_00000000_01100111_00000110_00000110;
          red = hzX;
          blue = 0;
          green = 0;
        end
      default:begin
          ss = 64'b0;
          red = 0;
          green = 0;
          blue = 0;
      end
    endcase

  end

endmodule