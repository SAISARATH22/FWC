#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

int main(void)

{

bool B,A;
bool Q1=0,Q2=0;

DDRD = 0b01100000;
DDRB = 0b00100000;
PORTD = 0b11000000;
PORTB = 0b00000011;

while(1)
{

	PORTB = ((1 << PB5));

	_delay_ms(200L);

B=((!Q1) && (!Q2));
A=(Q1);

PORTD = (B << 5);
PORTD = (A << 6);

Q1 = (PIND & (1 << PIND2)) == (1 << PIND2);
Q2 = (PIND & (1 << PIND3)) == (1 << PIND3);

	PORTB = ((0 << PB5));
	
	_delay_ms(200L);
}

	return 0;
}


