/*
	PressureSensorDriver.c
	Eng. Ahmed Essam
*/

#include "PressureSensorDriver.h"
#include "driver.h"

int PSD_pVal = 0;
const int pTimer = 100000;

PSD_enum PSD_state_id;
void (*PSD_state)();

void pDriver_init(){
	//Initialize PressureSensorDriver
}

STATE_def(PSD_reading){

	//State Name
	PSD_state_id = PSD_reading;

	//State Action
	PSD_pVal = getPressureVal();
	setPressureVal(PSD_pVal);
	PSD_state = STATE(PSD_waiting);
}

STATE_def(PSD_waiting){

	//State Name
	PSD_state_id = PSD_waiting;

	//State Action
	Delay(pTimer);
	PSD_state = STATE(PSD_reading);
}