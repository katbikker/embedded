#include <avr/io.h>
#include <stdlib.h>
#include "testHeader.h"

int main(void)
{
    while(1)
    {
         DDRB = 0xff;
        PORTB = (1<<2);
    }
    return 0;
}
