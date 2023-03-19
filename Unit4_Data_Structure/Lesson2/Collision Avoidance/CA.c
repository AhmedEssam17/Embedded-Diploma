/*
 * CA.c
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

CA_enum CA_state_id;

void (*CA_state)();

void US_set_distance(int distance){
	CA_distance = distance;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US -----Distance = %d-----> CA \n", CA_distance);
}

STATE_def(CA_waiting){

	//State Name
	CA_state_id = CA_waiting;

	//State Action
	CA_speed = 0;
	DC_set_speed(CA_speed);

	printf("CA_waiting state: Distance = %d, Speed = %d \n", CA_distance, CA_speed);
}

STATE_def(CA_driving){

	//State Name
	CA_state_id = CA_driving;

	//State Action
	CA_speed = 30;
	DC_set_speed(CA_speed);

	printf("CA_driving state: Distance = %d, Speed = %d \n", CA_distance, CA_speed);
}

