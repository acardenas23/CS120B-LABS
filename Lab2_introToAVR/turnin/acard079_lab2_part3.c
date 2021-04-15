/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: 
 *
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
	DDRC = 0xFF; PORTC = 0x00; //configures port C's pins as outputs and initializes output to 0x00
	
	//DDR configures port's pins to either input or output
	//8 bit output registersv(PORTC) (write only)
	//PIN register are read only
	//
    /* Insert your solution below */

	unsigned char tmpA = 0x00;

    while (1) {
	    tmpA = PINA & 0x0F;

	    if (tmpA == 0x00){
		    PORTC = 0x04;
	    }else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA ==0x08){
		    PORTC = 0x03;
	    }else if (tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 || tmpA == 0x0A || tmpA == 0x0C){
		    PORTC = 0x02;
	    }else if(tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E){
		    PORTC = 0x01;
	    }else{
		    PORTC = 0x80;
	    }
	    
	   
    }

    return 0;
}
