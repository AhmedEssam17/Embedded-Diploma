/*
 * US.c
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#include "US.h"

int randomDistance(int low, int high);

int US_distance = 0;
US_enum US_state_id;

void (*US_state)();

void US_init(){
	printf("=====US_INIT=====\n");
}

STATE_def(US_busy){

	//State Name
	US_state_id = US_busy;

	//State Action
	US_distance = randomDistance(45, 55);
	printf("US_busy state: Distance = %d \n", US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);
}


int randomDistance(int low, int high){
	int randomNum = (rand() % (high - low + 1)) + low;
	return randomNum;
}

