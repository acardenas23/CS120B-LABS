/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum states {SM1_START, SM1_PB0, SM1_PB0RELEASE, SM1_PB1, SM1_PB1RELEASE} state;

void TickFct()
{
	switch(state) {
		case SM1_START:
			state = SM1_PB0;
			break;
		case SM1_PB0:
			if(PINA & 0x01){
				state = SM1_PB0;
			}else{
				state = SM1_PB0RELEASE;
			}
			break;
		case SM1_PB0RELEASE:
			if(PINA & 0x01){
				state = SM1_PB1;
			}else{
				state = SM1_PB0RELEASE;
			}
			break;
		case SM1_PB1:
			if(PINA & 0x01){
				state = SM1_PB1;
			}else{
				state = SM1_PB1RELEASE;
			}
			break;
		case SM1_PB1RELEASE:
			if(PINA & 0x01){
				state = SM1_PB0;
			}else{
				state = SM1_PB1RELEASE;
			}
			break;
		default:
			state = SM1_START;
			break;
	}
	switch(state){
		case SM1_START:
			PORTB = 0x01;
			break;
		case SM1_PB0:
			PORTB = 0x01;
			break;
		case SM1_PB0RELEASE:
			PORTB = 0x01;
			break;
		case SM1_PB1:
			PORTB = 0x02;
			break;
		case SM1_PB1RELEASE:
			PORTB = 0x02;
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // PORTA is input
	DDRB = 0xFF; PORTB = 0x00; //PORTB is output

    /* Insert your solution below */
    while (1) {
	    TickFct();


    }
    return 1;
}
