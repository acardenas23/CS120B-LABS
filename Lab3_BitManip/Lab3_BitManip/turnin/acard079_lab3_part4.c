/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description:
 *	Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4. That is to say,  take the upper nibble of PINA and map it to the lower nibble of PORTB, likewise take the lower nibble of PINA and map it to the upper nibble of PORTC 
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
	DDRB = 0xFF, PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	    //PA7 -> PB3, PA6 -> PB2, … PA1 -> PC5, PA0 -> PC4
	    tmpB = 0x00;
	    tmpC = 0x00;

	    tmpA = PINA & 0xF0; //get upper nibble of PINA
	    tmpB = tmpA >> 4; //get upper nibble to lower nibble

	    tmpA = PINA & 0x0F; //get lower nibble of PINA
	    tmpC = tmpA << 4; //map to the upper nibble of PORTC

	    PORTB = tmpB;
	    PORTC = tmpC;


		    	
    }

    return 1;
}
