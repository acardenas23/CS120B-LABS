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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cntA = 0x00;
	//unsigned char cntB = 0x00;
	//unsigned char total = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	//unsigned char mask = 0x00;
	unsigned char i = 0x00;
	unsigned char length = 0x00;

    /* Insert your solution below */
    while (1) {

	    tmpA = PINA;
	    tmpB = PINB;
	    length = 0x08;
	    cntA = 0x00;

	    for (i = 0x00 ; i <= length; i = i + 1){
		    if(tmpA & 0x01){
			    cntA = cntA + 1;
		    }
		    tmpA = tmpA >> 1;
		    if(tmpB & 0x01){
			    cntA = cntA + 1;
		    }
		    tmpB = tmpB >> 1;
	    }

	    //total = cntA + cntB;
	    //want 0000 1000, got 0010 1100
	    PORTC = cntA;
		    	
    }

    return 1;
}
