/*
	ComparingAlgorithm.c
	Eng. Ahmed Essam
*/

#include "ComparingAlgorithm.h"

int CA_pVal = 0;
const int threshold = 20;

CA_enum CA_state_id;
void (*CA_state)();

void setPressureVal(int pVal){
	CA_pVal = pVal;
	CA_state = STATE(CA_detect);
}

STATE_def(CA_detect){

 	//State Name
	CA_state_id = CA_detect;

	//State Action
	if(CA_pVal > threshold){
		highPressureFlag();
	}
	CA_state = STATE(CA_waiting);
}

STATE_def(CA_waiting){

	//State Name
	CA_state_id = CA_waiting;
}

