module helloworldfpga(
    input wire X,
    input wire Y,
    input wire Z,
 
    output wire optiona,
    output wire optionb,
    output wire optionc,
    output wire optiond
    );

    always @(*)
    begin
 	optiona = (((X^Y)^Z)==(X^(Y^Z)));
	optionb = (((X|Y)^Z)==(X^(Y|Z)));
	optionc = ((X^Y)==(X|Y));
	optiond = ((X^Y)==(~((X&Y)|((~X)&(~Y)))));
    end
endmodule
