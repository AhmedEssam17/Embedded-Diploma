/*
 * DC.c
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#include "DC.h"

int DC_speed = 0;
DC_enum DC_state_id;

void (*DC_state)();

void DC_init(){
	printf("=====DC_INIT===== \n");
}

void DC_set_speed(int speed){
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CA -----Speed = %d-----> DC \n", DC_speed);
}

STATE_def(DC_idle){

	//State Name
	DC_state_id = DC_idle;

	//State Action
	/*
	 * Call PWM to set speed = DC_speed
	*/
	printf("DC_idle state: Speed = %d \n", DC_speed);
}

STATE_def(DC_busy){

	//State Name
	DC_state_id = DC_busy;

	//State Action
	/*
	 * Call PWM to set speed = DC_speed
	*/
	DC_state = STATE(DC_idle);
	printf("DC_busy state: Speed = %d \n", DC_speed);
}

