/*
	AlarmMonitor.c
	Eng. Ahmed Essam
*/

#include "AlarmMonitor.h"

const int aTimer = 60000;
AM_enum AM_state_id;
void (*AM_state)();

void highPressureFlag(){
	AM_state = STATE(AM_alarmON);
}

STATE_def(AM_alarmOFF){

	//State Name
	AM_state_id = AM_alarmOFF;
}

STATE_def(AM_alarmON){

	//State Name
	AM_state_id = AM_alarmON;

	//State Action
	startAlarm();
	AM_state = STATE(AM_waiting);
}

STATE_def(AM_waiting){

	//State Name
	AM_state_id = AM_waiting;

	//State Action
	Delay(aTimer);
	stopAlarm();
	AM_state = STATE(AM_alarmOFF);
}
