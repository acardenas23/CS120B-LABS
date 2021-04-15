/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C. 
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTD = 0x00;

	unsigned char cntA = 0x00;
	unsigned char cntB = 0x00;
	unsigned char total = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char mask = 0x00;

    /* Insert your solution below */
    while (1) {

	    tmpA = PINA;
	    tmpB = PINB;
	    mask = 0x01;

	    while(mask<=0x08){
		    if((tmpA & mask) > 0x00){
			    cntA = cntA + 1;
		    }
		    mask = mask << 1;
		    //mask is 0001->0010->0100->1000
	    }

	    mask = 0x01;

	    while(mask<=0x08){
		    if((tmpB & mask) > 0x00){
			    cntB = cntB + 1;
		    }
		    mask = mask << 1;
	    }

	    total = cntB + cntA;
	    PORTC = total;

    }
    return 1;
}
