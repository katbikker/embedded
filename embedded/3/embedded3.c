#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "embedded3.h" //cpu clock speed 16mhz, baudrate 9600

int8_t lampje;

ISR(INT1_vect)
{
    PORTB = (1<<lampje);
    lampje++;
    
    if(lampje == 4)
    {
    	lampje = 0;
    }
}

int main(void)
{
    DDRB = 0xff;
  	lampje = 0;
  	
  	EICRA = (1<<ISC11);
  	EIMSK = (1<<INT1);
  	
  	sei();
  	
  	while(1);
    
    return (0);
}
