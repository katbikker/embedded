
#include <avr/io.h>
#include <stdlib.h>
#include "embedded_2d.h" //cpu clock speed 16mhz, baudrate 9600
int lampje
ISR(INT1_vect)
{
  	lampje++
    if(lampje == 4)
    {
    	lampje = 0;
    }
    PORTB = (1<<lampje);
}

int main(void)
{

    DDRB = 0xff;
  	lampje = 0;
  	sei();
  	EICRA = (1<<ISC11);
  	EIMSK = (1<<INT1);
  	while(1);

    return (0);
}
