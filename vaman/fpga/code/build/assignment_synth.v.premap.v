/* Generated by Yosys 0.9+2406 (git sha1 ca763e6d5, gcc 10.2.1-6 -fPIC -Os) */

(* top =  1  *)
(* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:1.1-17.10" *)
module insss(clk, in, c, d, a, b);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:4.8-4.9" *)
  output a;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:4.10-4.11" *)
  output b;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:6.1-11.4" *)
  wire b_dff_Q_D;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:3.12-3.13" *)
  output c;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:6.1-11.4" *)
  wire c_dff_Q_D;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:2.7-2.10" *)
  input clk;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:3.14-3.15" *)
  output d;
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:2.11-2.13" *)
  input in;
  ckpad #(
    .IO_LOC("X24Y3"),
    .IO_PAD("59"),
    .IO_TYPE("BIDIR")
  ) _05_ (
    .P(clk),
    .Q(_00_)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X16Y3"),
    .IO_PAD("62"),
    .IO_TYPE("BIDIR")
  ) _06_ (
    .A(_01_),
    .P(a)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X18Y3"),
    .IO_PAD("63"),
    .IO_TYPE("BIDIR")
  ) _07_ (
    .A(_02_),
    .P(b)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X20Y3"),
    .IO_PAD("61"),
    .IO_TYPE("BIDIR")
  ) _08_ (
    .A(_03_),
    .P(c)
  );
  (* keep = 32'd1 *)
  outpad #(
    .IO_LOC("X22Y3"),
    .IO_PAD("60"),
    .IO_TYPE("BIDIR")
  ) _09_ (
    .A(_03_),
    .P(d)
  );
  (* keep = 32'd1 *)
  inpad #(
    .IO_LOC("X14Y3"),
    .IO_PAD("64"),
    .IO_TYPE("BIDIR")
  ) _10_ (
    .P(in),
    .Q(_04_)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:12.1-15.4|/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_ffs_map.v:14.9-14.50" *)
  dff a_dff_Q (
    .CLK(_00_),
    .D(_03_),
    .Q(_01_)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:6.1-11.4|/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_ffs_map.v:14.9-14.50" *)
  dff b_dff_Q (
    .CLK(_00_),
    .D(b_dff_Q_D),
    .Q(_02_)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/fpga-examples/blink/assignment.v:6.1-11.4|/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_ffs_map.v:14.9-14.50" *)
  dff c_dff_Q (
    .CLK(_00_),
    .D(c_dff_Q_D),
    .Q(_03_)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_lut_map.v:32.63-32.110" *)
  LUT2 #(
    .EQN("(~I0*~I1)+(~I0*I1)+(I0*I1)"),
    .INIT(4'hd)
  ) in_LUT2_I0 (
    .I0(_04_),
    .I1(_01_),
    .O(c_dff_Q_D)
  );
  (* module_not_derived = 32'd1 *)
  (* src = "/data/data/com.termux/files/home/symbiflow/bin/../share/yosys/quicklogic/pp3_lut_map.v:32.63-32.110" *)
  LUT2 #(
    .EQN("(I0*~I1)+(~I0*I1)"),
    .INIT(4'h6)
  ) in_LUT2_I0_1 (
    .I0(_04_),
    .I1(_01_),
    .O(b_dff_Q_D)
  );
endmodule