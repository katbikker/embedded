#include <avr/io.h>
#include <stdlib.h>
#include "embedded_2d.h" //cpu clock speed 16mhz, baudrate 9600
#include <util/delay>

#define D 293.66
#define Ds 311.13
#define F 349.23
#define G 392


#define tijdsduur1 500
#define tijdsduur2 100

void playNoot(float freg, uint16_t tijd)
{
    TCCR1A |= (1<<COM1B0);
    TCCR1B |= (1<<WGM12) | (1<<CS10);//geen prescaler. ctc modus.
    OCR1B = (4000000/freq) -1;//8000000 / (freq x 2)
    _delay_ms(tijd);
    TCCR1A = 0;
    TCCR1B = 0;
}

int main(void)
{
    while(1)
    {
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
        playNoot(D, 4*tijdsduur1);
    }

    return 0;
}
