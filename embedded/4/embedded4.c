#include <avr/io.h>
#include <stdlib.h>
#include <avr/delay.h>
#include "embedded4.h" //cpu clock speed 16mhz, baudrate 9600

#define WAARDE1 200

uint16_t adc()
{
    uint16_t adcValue;

    ADCSRA |= (1 << ADSC| 1<<ADIF);                     /* start ADC conversion */
    while(~ADCSRA & (1<<ADIF));
    adcValue = ADC;                                     /* read ADC in */

    return adcValue;
}

int main(void) {

  uint16_t potmeter, ldr;
  DDRB=0x02;

  ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC   MUX1 = 0 -> ADC0   MUX1 = 1 -> ADC2 */
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1);                   /* ADC clock prescaler /64 */
  ADCSRA |= (1 << ADEN);                                 /* enable ADC */

   // ------ Event loop ------ //
  while (1) {
    ADMUX &= ~(1<<MUX1);//selecteer ADC0
    potmeter = adc();
    ADMUX |= (1<<MUX1);//selecteer ADC2
    ldr = adc();

    if(ldr > potmeter )
    {
        PORTB |=(1<<PORTB1);
    }
    else
    {
        PORTB &= ~(1<<PORTB1);
    }

    _delay_ms(250);
  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
