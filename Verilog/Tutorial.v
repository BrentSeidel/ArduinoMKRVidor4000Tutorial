/*
Tutorial with some simple logic gates.  This is intended to be
a minimal model that shows some of the basics.
*/
module Tutorial

`include "MKRVIDOR4000_pins.v"

/*
  Inputs are bMKR_D[0] and bMKR_D[1].
*/
//  Assignments to rename the inputs.
assign in_a=bMKR_D[0];
assign in_b=bMKR_D[1];
/*
  Outputs are:
    bMKR[2] <= NOT in_a
    bMKR[3] <= NOT in_b
    bMKR[4] <= in_a AND in_b
	bMKR[5] <= in_a OR in_b
	bMKR[6] <= in_a XOR in_b
*/
// Set the outputs
assign bMKR_D[2]=!in_a;
assign bMKR_D[3]=!in_b;
assign bMKR_D[4]=in_a && in_b;
assign bMKR_D[5]=in_a || in_b;
assign bMKR_D[6]=(in_a && !in_b) || (!in_a && in_b);

endmodule
