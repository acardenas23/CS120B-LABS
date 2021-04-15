/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description:
 *	A car's passenger seat weight sensor outputs a 9-bit value (ranging from 0 to 511) and connects to input PD7...PD0PB0 on the microcontroller. If the weight is equal to or above 70 pounds, the airbag should be enabled by setting PB1 to 1. If the weight is above 5 but below 70, the airbag should be disabled and an "Airbag disabled" icon should light by setting PB2 to 1. (Neither B1 nor B2 should be set if the weight is 5 or less, as there is no passenger). 
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
	DDRB = 0xFE, PORTB = 0x01; //make B0 input, B7..B1 output
	DDRC = 0x00; PORTD = 0xFF; //output PIND input

	unsigned char tmpB0 = 0x0000;
	unsigned short weight = 0x0000;
	unsigned char tmpB1 = 0x00;
	unsigned char tmpB2 = 0x00;

    /* Insert your solution below */
    while (1) {
	   
	    //input PD7..PD0PB0
	    weight = PIND << 1;
	    tmpB0 = PINB & 0x01; //get B0
	    weight = weight | tmpB0;


	    if(weight >= 0x46){
		    tmpB1 = 0x02;
	    }else{
		    tmpB1 = 0x00;
	    }

	    if((weight > 0x05) && (weight < 0x46)){
		    tmpB2 = 0x04;
	    }else{
		    tmpB2 = 0x00;
	    }

	    PORTB = tmpB1 | tmpB2;


		    	
    }

    return 1;
}
