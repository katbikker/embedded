#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "embedded6.h" //cpu clock speed 16mhz, baudrate 9600

uint8_t ovfCounter;
uint8_t richting;

ISR(TIMER0_OVF_vect)
{
    ovfCounter++;
    
    if(ovfCounter == 29) //8000000 / 1024 / 256 = 30 - 1 = 29
    {
        ovfCounter = 0; //set overflow counter to 0
        
        if(richting == 0)
        {
            OCR1A = 25;            
            richting = 1;
        }
        else
        {
            OCR1A = 12;
            richting = 0;
        }
    }
}

void timer0()
{
    TCCR0A = 0;
    TCCR0B |= (1<<CS02) | (1<<CS00);
    TIMSK0 |= (1<<TOIE0);//enable compare interrupt.
}

void timer1()
{
    TCCR1A = (1<<COM1A1) | (1<<WGM10);
    TCCR1B |= (1<<CS12) | (1<<CS10);
}

int main()
{
    timer0();
    timer1();
    
    sei();
    ovfCounter = 0;
    richting = 0;
    OCR1A = 12;
    
    while(1)
    {

    }

  return 0;
}
