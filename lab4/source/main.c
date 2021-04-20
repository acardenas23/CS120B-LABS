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

enum states {START, WAIT, WAIT2, HOLDINC, HOLDDEC, INC, DEC, RESET} state;


void TickFct()
{
	switch(state){
		case START:
			state = WAIT;
			break;
		case WAIT:
			state = WAIT2;
			break;
		case WAIT2:
			if(PINA == 0x01){
				state = INC;
			}else if(PINA == 0x02){
				state = DEC;
			}else if(PINA == 0x03){
				state = RESET;
			}else if(PINA == 0x00){
				state =  WAIT2;
			}
			break;
		case HOLDINC:
			if(PINA == 0x01){
				state = HOLDINC;
			}else if(PINA == 0x03){
				state = RESET;
			}else if(PINA == 0x02){
				state = DEC;
			}else{
				state = WAIT2;
			}
			break;
		case HOLDDEC:
			if(PINA == 0x02){
				state = HOLDDEC;
			}else if(PINA == 0x03){
				state = RESET;
			}else if(PINA == 0x01){
				state = INC;
			}else{
				state = WAIT2;
			}
			break;
			
		case INC:
			state = HOLDINC;
			break;
		case DEC:
			state = HOLDDEC;
			break;
		case RESET:
			if(PINA == 0x03){
				state = RESET;
			}else{
				state = WAIT2;
			}
			break;
		default:
			state = START;
			break;
	}
	switch(state){
		case START:
			PORTC = 0x07;
			break;
		case WAIT:
			PORTC = 0x07;
			break;
		case WAIT2:
			break;
		case HOLDINC:
			break;
		case HOLDDEC:
			break;
		
		case INC:
			if(PORTC < 0x09){
				PORTC = PORTC + 0x01;
			}else{
				PORTC = 0x09;
			}
			break;
		case DEC:
			if(PORTC > 0x00){
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
	state = START;
    /* Insert your solution below */
    while (1) {
	    TickFct();
    }
    return 1;
}
