/*
 * main.c
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup(){

	//Initialize Blocks
	US_init();
	DC_init();

	//Set State pointers to their corresponding block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

void main(){

	setup();

	volatile int d;

	while(1){
		//Call state pointer of each block
		US_state();
		CA_state();
		DC_state();

		//Delay loop
		for(d = 0; d < 1000; d++);
	}
}
