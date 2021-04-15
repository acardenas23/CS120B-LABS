/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;//configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; //configures port B's pins as outputs and initializes output to 0x00

	//DDR configures port's pins to either input or output
	//8 bit output registersv(PORTA, PORTB) (write only)
	//PIN register are read only
	//
    /* Insert your solution below */

	//PA0 refers to PORTA's bit 0
	//PA1 PORTA's bit 1
	unsigned char tmpA0 = 0x00;
	unsigned char tmpA1 = 0x00;
    while (1) {
	    //if light is not sensed and garage door is open ->illuminate
	    tmpA0 = PINA & 0x01; //garage door opened (PA0)
	    tmpA1 = (PINA & 0x02)>>1; //light sensed (PA1)
	    //PA1 = 0000 0010>>1 = 0000 00001
	    if(tmpA0 && !tmpA1){
		    PORTB = 0x01;
	    }else{
		    PORTB = 0x00;
	    }
    }
    return 0;
}
