/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #4
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF; 
	DDRD = 0xFF; PORTD = 0x00; //configures port D's pins as outputs and initializes output to 0x00
	
	//DDR configures port's pins to either input or output
	//8 bit output registersv(PORTC) (write only)
	//PIN register are read only
	//
    /* Insert your solution below */

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char weight = 0x0000;
	unsigned char tmpD0 = 0x00;
	unsigned char tmpD1 = 0x00;
	unsigned char tmpD = 0x0000;

    while (1) {
	    tmpA = PINA;
	    tmpB = PINB;
	    tmpC = PINC;

	    weight = tmpA + tmpB + tmpC;

	    if(weight>0x008C){
		    tmpD0 = 0x01;
	    }else{
		    tmpD0 = 0x00;
	    }

	    if((tmpA-tmpC)>0x50 || (tmpC-tmpA)>0x50){
		    tmpD1 = 0x02;
	    }else{
		    tmpD1 = 0x00;
	    }

	    //1111 1100 = 0xFC
	    weight = weight >> 2;

	    tmpD = (weight & 0xFC) | tmpD0 | tmpD1;
	    PORTD = tmpD;

	    //expected 0011 0001 but getting 1100 0001
	    
	   
    }

    return 0;
}
