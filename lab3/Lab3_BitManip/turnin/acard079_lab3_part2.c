/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: 
 *	A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full). A series of LEDs connected to PC5..PC0 should light to graphically indicate the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4, PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or less.  (The example below shows the display for a fuel level of 3). 
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpC6 = 0x00;

    /* Insert your solution below */
    while (1) {

	    //if fuel level is 1 || 2 -> PC5 lights
	    //if fuel level is 3 || 4 -> PC5 and PC4 lights
	    //5 || 6 -> PC5..PC3
	    //7 ||8||9 -> PC5..PC2
	    //10||12 -> PC5..PC1
	    //13-15 -> PC5-> PC0
	    tmpA = PINA&0x0F; //get PINS A3 TO A0
	    tmpC = 0x00;
	    tmpC6 = 0x00;

	    if(tmpA >= 0x0D){
		    //0011 1111
		    tmpC = 0x3F;
	    }else if (tmpA >=0x0A){
		    //0011 1110
		    tmpC = 0x3E;
	    }else if (tmpA >= 0x07){
		    //0011 1100
		    tmpC = 0x3C;
	    }else if (tmpA >= 0x05){
		    tmpC = 0x38;
	    }else if (tmpA >= 0x03){
		    tmpC = 0x30;
	    }else if (tmpA >= 0x01){
		    tmpC = 0x02;
	    }

	    if(tmpA <= 0x04){
		    //0100 0000
		    tmpC6 = 0x40;
	    }

	    PORTC = tmpC6 | tmpC;

		    	
    }

    return 1;
}
