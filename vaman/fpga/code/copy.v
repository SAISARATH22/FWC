module insss(
input wire clk,
input wire in,
output wire a,
output wire b,
output wire c,
output wire d
);
always@(posedge clk)
begin
a=1'b0;
in=1'b0;
b=a^in;
c=~(b & in);
d<=c;
end
always@(posedge clk)
begin 
a<=d;
end

endmodule
