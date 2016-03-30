/* set clock speed and baud rate */
#define F_CPU 16000000 //set cpu clock speed
#define BAUD 9600 //set baudrate

/* choose baudrate calculation for chosen mode in UBRRnL/H */
#define BAUD_AN (F_CPU/(16*BAUD))-1 //asynchronous normal mode
#define BAUD_ADS (F_CPU/(8*BAUD))-1 //asynchronous double speed mode
#define BAUD_SM (F_CPU/(2*BAUD))-1 //synchronous master mode
