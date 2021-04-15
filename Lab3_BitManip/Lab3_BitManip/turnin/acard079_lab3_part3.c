/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #3
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpC6 = 0x00;
	unsigned char tmpC7 = 0x00;

    /* Insert your solution below */
    while (1) {

	    //if fuel level is 1 || 2 -> PC5 lights
	    //if fuel level is 3 || 4 -> PC5 and PC4 lights
	    //5 || 6 -> PC5..PC3
	    //7 ||8||9 -> PC5..PC2
	    //10||12 -> PC5..PC1
	    //13-15 -> PC5-> PC0

	    tmpA = PINA & 0x0F;
	    tmpC = 0x00;
	    tmpC6 = 0x00;
	    tmpC7 = 0x00;

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
	    }else{
		    tmpC = 0x00;
	    }

	    if (tmpA <= 0x04){
		    //0100 0000
		    tmpC6 = 0x40;
	    }else{
		    tmpC6 = 0x00;
	    }

	    //PC7 = 1 if a key is in the ignition(PA4), a driver is seated(PA5), and !PA6
	    //0111 0000 = 0x70
	    tmpA = PINA & 0x70; //get PA6-PA4

	    //0011 0000

	    if(tmpA == 0x30){
		    tmpC7 = 0x80;
	    }else{
		    tmpC7 = 0x00;
	    }


	    PORTC = tmpC7 | tmpC6 | tmpC;

		    	
    }

    return 1;
}
