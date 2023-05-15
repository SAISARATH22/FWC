/* Generated by Yosys 0.9+2406 (git sha1 ca763e6d5, gcc 10.2.1-6 -fPIC -Os) */

(* top =  1  *)
(* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:1.1-19.10" *)
module helloworldfpga(X, Y, Z, optiona, optionb, optionc, optiond);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:2.16-2.17" *)
  input X;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:3.16-3.17" *)
  input Y;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:4.16-4.17" *)
  input Z;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:6.17-6.24" *)
  output optiona;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:7.17-7.24" *)
  output optionb;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:8.17-8.24" *)
  output optionc;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/helloworldfpga.v:9.17-9.24" *)
  output optiond;
  logic_1 _06_ (
    .a(_00_)
  );
  (* keep = 32'd1 *)
  inpad #(
    .IO_LOC("X14Y3"),
    .IO_PAD("64"),
    .IO_TYPE("BIDIR")
  ) _07_ (
    .P(X),
    .Q(_01_)
  );
  (* keep = 32'd1 *)
  inpad #(
    .IO_LOC("X16Y3"),
    .IO_PAD("62"),
    .IO_TYPE("BIDIR")
  ) _08_ (
    .P(Y),
    .Q(_02_)
  );
  (* keep = 32'd1 *)
  inpad #(
    .IO_LOC("X18Y3"),
    .IO_PAD("63"),
    .IO_TYPE("BIDIR")
  ) _09_ (
    .P(Z),
    .Q(_03_)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X24Y3"),
    .IO_PAD("59"),
    .IO_TYPE("BIDIR")
  ) _10_ (
    .A(_00_),
    .P(optiona)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X26Y3"),
    .IO_PAD("57"),
    .IO_TYPE("BIDIR")
  ) _11_ (
    .A(_04_),
    .P(optionb)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X28Y3"),
    .IO_PAD("56"),
    .IO_TYPE("BIDIR")
  ) _12_ (
    .A(_05_),
    .P(optionc)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X30Y3"),
    .IO_PAD("55"),
    .IO_TYPE("BIDIR")
  ) _13_ (
    .A(_00_),
    .P(optiond)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_lut_map.v:36.63-36.121" *)
  LUT3 #(
    .EQN("(~I0*~I1*~I2)+(I0*~I1*~I2)+(I0*I1*~I2)+(I0*~I1*I2)+(~I0*I1*I2)"),
    .INIT(9'h0d7)
  ) optionb_LUT3_O (
    .I0(_02_),
    .I1(_03_),
    .I2(_01_),
    .O(_04_)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_lut_map.v:32.63-32.110" *)
  LUT2 #(
    .EQN("(~I0*~I1)+(I0*~I1)+(~I0*I1)"),
    .INIT(4'h7)
  ) optionc_LUT2_O (
    .I0(_02_),
    .I1(_01_),
    .O(_05_)
  );
endmodule