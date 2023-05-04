/*
	AlarmActuatorDriver.c
	Eng. Ahmed Essam
*/

#include "AlarmActuatorDriver.h"
#include "driver.h"

AAD_enum AAD_state_id;
void (*AAD_state)();

void startAlarm(){
	AAD_state = STATE(AAD_alarmON);
}

void stopAlarm(){
	AAD_state = STATE(AAD_alarmOFF);
}

void aDriver_init(){
	//Initialize AlarmActuatorDriver
}

STATE_def(AAD_alarmOFF){

	//State Name
	AAD_state_id = AAD_alarmOFF;

	//State Action
	Set_Alarm_actuator(turnOFF);
	AAD_state = STATE(AAD_waiting);
}

STATE_def(AAD_alarmON){

	//State Name
	AAD_state_id = AAD_alarmON;

	//State Action
	Set_Alarm_actuator(turnON);
	AAD_state = STATE(AAD_waiting);
}

STATE_def(AAD_waiting){

	//State Name
	AAD_state_id = AAD_waiting;
}
