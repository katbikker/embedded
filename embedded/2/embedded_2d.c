#include <avr/io.h>
#include <stdlib.h>
#include "embedded_2d.h" //cpu clock speed 16mhz, baudrate 9600

unsigned char receive(void)
{
    while(~UCSR0A & (1<<RXC0));
    return UDR0;
}

uint8_t leesinteger(void)
{
    int i;
    int nummer;
    uint8_t shizzle;
    char karakter, array[32];
    
    for(i = 0; karakter != 0x20; i++)
    {
        karakter = receive();
        array[i] = karakter;
    }
    array[i] = '\0';
    nummer = atoi(array);
    shizzle = nummer;
    return shizzle;
}


int main(void)
{
    UCSR0A = (1 << U2X0); //asynchronous double speed mode
    UCSR0B = (1 << RXEN0); //enable usart receiver
    UCSR0C = (1 << UCSZ01) | (1 << UPM01); //7 data bits, 1 stop bit, even parity

    UBRR0H = 00;
    UBRR0L = 103;
    
    DDRB = 0xff;
    
    while(1)
    {
        PORTB = leesinteger();
    }
    return (0);
}

