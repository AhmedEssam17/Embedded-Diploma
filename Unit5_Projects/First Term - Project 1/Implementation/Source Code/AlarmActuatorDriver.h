/*
	AlarmActuatorDriver.h
	Eng. Ahmed Essam
*/

#ifndef AAD_H_
#define AAD_H_

#include "state.h"

typedef enum{
	AAD_alarmOFF,
	AAD_alarmON,
	AAD_waiting
} AAD_enum;
extern AAD_enum AAD_state_id;

#define turnON 	0
#define turnOFF 1

void aDriver_init();

STATE_def(AAD_alarmOFF);
STATE_def(AAD_alarmON);
STATE_def(AAD_waiting);

extern void (*AAD_state)();

#endif /* AAD_H_ */