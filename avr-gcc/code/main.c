#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

void loop()
{

    generateTone(12000, 2000);
    _delay_ms(2000); 
}

void generateTone(uint16_t frequency, uint16_t duration)
{
    uint16_t period = 1000000 / frequency; 
    uint16_t pulseWidth = period / 2;     

    uint16_t numCycles = frequency * duration / 1000; 

    for (uint16_t i = 0; i < numCycles; i++)
    {
        PORTB |= (1 << PB5); 
        _delay_us(42);       
        PORTB &= ~(1 << PB5); 
        _delay_us(42);       
    }
}
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
    generateTone(12000, 2000);

	PORTB = ((1 << PB5));

	_delay_ms(200L);

B=((!Q1) && (!Q2));
A=((Q1) && (!Q2));

PORTD = (A << 5);
PORTD = (B << 6);

Q1 = (PIND & (1 << PIND2)) == (1 << PIND2);
Q2 = (PIND & (1 << PIND3)) == (1 << PIND3);

	PORTB = ((0 << PB5));
	
	_delay_ms(200L);
}

	return 0;
}


