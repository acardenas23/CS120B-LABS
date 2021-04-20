/*	Author: acard079
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #4  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum states {START, INIT, UNLOCKEDPOUND2, UNLOCKEDPOUND, HOLDCODE2, HOLDPOUND2, HOLDPOUND, UNLOCKED, HOLDY, LOCKED} state;


void TickFct()
{
	switch(state){
		case START:
			state = INIT;
			break;
		case INIT:
			if(PINA == 0x04){
				state = UNLOCKEDPOUND;
			}else if(PINA == 0x80){
				state = LOCKED;
			}else{
				state = INIT;
			}
			break;
		case UNLOCKEDPOUND:
			if(PINA == 0x04){
				state = UNLOCKEDPOUND;
			}else if(PINA == 0x00){
				state = HOLDPOUND;
			}else{
				state = LOCKED;
			}
			break;
		case HOLDPOUND:
			if(PINA == 0x00){
				state = HOLDPOUND;
			}else if(PINA == 0x02){
				state = UNLOCKED;
			}else{
				state = LOCKED;
			}
			break;
		case UNLOCKED:
			if(PINA == 0x02){
				state = HOLDY;
			}else if(PINA == 0x00){
				state = HOLDCODE2;
				//no button is pressed
			}else{
				state = INIT;
			}
			break;
		case HOLDCODE2:
			if(PINA == 0x04){
				state = UNLOCKEDPOUND2;
			}else{
				state = INIT;
			}
			break;
		case UNLOCKEDPOUND2:
			if(PINA == 0x00){
				state = HOLDPOUND2;
			}else if(PINA == 0x02){
				state = LOCKED;
			}else{
				state = UNLOCKED;
			}
			break;
		case HOLDY:
			if((PINA & 0x07) == 0x02){
				state = HOLDY;
			}else if(((PINA & 0x80) == 0x80)|| (PINA == 0x06)){
				state = LOCKED;
			}else{
				state = INIT;
			}
			break;
		case LOCKED:
			if((PINA == 0x80)||(PINA == 0x06)){
				state = LOCKED;
			}else{
				state = INIT;
			}
			break;
		default:
			state = START;
			break;
	}
	switch(state){
		case START:
			PORTB = 0x00;
			break;
		case INIT:
			break;
		case UNLOCKEDPOUND:
			break;
		case HOLDPOUND:
			break;
		case UNLOCKED:
			PORTB = 0x01;
			break;
		case HOLDY:
			PORTB = 0x00;
			break;
		case LOCKED:
			PORTB = 0x00;
			break;
		case UNLOCKEDPOUND2:
			break;
		case HOLDPOUND2:
			break;
		case HOLDCODE2:
			break;


		default:
			PORTB = 0x00;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // PORTA is input
	DDRB = 0xFF; PORTB = 0x00; //PORTB is output
	state = START;
    /* Insert your solution below */
    while (1) {
	    TickFct();
    }
    return 1;
}
