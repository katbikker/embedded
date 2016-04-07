#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/delay.h>

#include "embedded5.h" //cpu clock speed 16mhz, baudrate 9600

#define D 293.66
#define Ds 311.13
#define F 349.23
#define G 392

#define tijdsduur1 500
#define tijdsduur2 100

void playNoot(float freg, uint16_t tijd)
{
    TCCR1A |= (1<<COM1B0); //zet timer aan
    TCCR1B |= (1<<WGM12) | (1<<CS10);//timer geen prescaler. ctc modus.
    
    OCR1B = (4000000/freg) -1;//8000000 / (freq x 2) //initialiseer frequentie
    
    _delay_ms(500); //rust
    
    TCCR1A = 0; //timer uit
    TCCR1B = 0; //timer uit
}
int main(void)
{
    DDRB = 0xff;
    PORTB = (1<<2);
    
    while(1)
    {
            PORTB = (1<<2);
        playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        /*playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(Ds, 4*tijdsduur1);
        _delay_ms(2*tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(D, 4*tijdsduur1);
        _delay_ms(1000);
        playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(G, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(Ds, 4*tijdsduur1);
        _delay_ms(2*tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(F, tijdsduur1);
        _delay_ms(tijdsduur2);
        playNoot(D, 4*tijdsduur1);*/
    }

    return 0;
}
