/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum states {START, INCREMENT, HOLD, DECREMENT, RESET, WAIT} state;

void TickFct()
{
	switch(state){
		case START:
			state = WAIT;
			PORTC = 0x07;
			break;
		case WAIT:
			if(PINA == 0x01){
				state =INCREMENT;
			}else if(PINA == 0x02){
				state = DECREMENT;
			}else if(PINA == 0x03){
				state = RESET;
			}else{
				state = HOLD;
			}
			break;
		case INCREMENT:
			state = HOLD;
			break;
		case DECREMENT:
			state = HOLD;
			break;
		case HOLD:
			if(PINA == 0x03){
				state = RESET;
			}else if(PINA == 0x00){
				state = WAIT;
			}else{
				state = HOLD;
			}
			break;
		case RESET:
			if(PINA == 0x03){
				state = RESET;
			}else{
				state = HOLD;
			}
			break;
		default:
			state = WAIT;
			break;
	}
	switch(state){
		case START:
			PORTC = 0x07;
			break;
		case WAIT:
			break;
		case HOLD:
			break;
		case INCREMENT:
			if(PORTC < 0x09){
				PORTC = PORTC + 0x01;
			}else{
				PORTC = 0x09;
			}
			break;
		case DECREMENT:
			if(PORTC > 0){
				PORTC = PORTC - 0x01;
			}else{
				PORTC = 0x00;
			}
			break;
		case RESET:
			PORTC = 0x00;
			break;
		default:
			PORTC = 0x07;
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // PORTA is input
	DDRC = 0xFF; PORTC = 0x00; //PORTB is output

    /* Insert your solution below */
    while (1) {
	    TickFct();
    }
    return 1;
}
