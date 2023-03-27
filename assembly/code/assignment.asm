.include "/sdcard/assembly/assignment/m328Pdef.inc"
.def x=r18
.def y=r19
.def z=r20
.def A=r21
.def B=r22
.def C=r23
.def D=r24
.def i=r27

setup:

ldi r16,0b00111100
out DDRD,r16

ldi r17,0b00100000
out DDRB,r17

ldi r25,0b11111111

loop:

in r18,pinD
ldi r26,0b01000000
and r26,r25
mov r18,r26
lsr r18

in r19,pinD
ldi r26,0b10000000
and r26,r25
mov r19,r26
lsr r19
lsr r19

in r20,pinB
ldi r26,0b00000001
and r26,r25
mov r20,r26
ldi r30,0b00000101
rcall assembly

out PortB,r17
call delay
;for A
mov r26,r19
mov r28,r20
and r26,r28
mov r28,r27
and r26,r28
mov r21,r26
;for B
mov r26,r19
com r26
and r26,r20
and r26,r27
mov r31,r19
com r20
com r27
and r31,r20
and r31,r27
mov r29,r18
and r29,r20
and r29,r27
or r26,r31
or r26,r29
mov r22,r26
com r20
com r27
;for C
mov r23,r27
com r23
;for D
mov r26,r18
com r27
and r26,r27
mov r24,r26
com r27

com r17
out portB,r17
call delay
call output
rjmp loop
start:rjmp start 

output:ldi r26,0b00100000
and r26,r16
out PortD,r26

assembly:lsl r20
	 dec r30
	 brne assembly
	 ret

delay:ldi r23,100
loop1:
ldi r24,100
loop2:
ldi r29,100
loop3:
dec r29
brne loop2
dec r24
brne loop1
dec r23
brne delay
ret
