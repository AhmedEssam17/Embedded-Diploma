/*
	AlarmMonitor.h
	Eng. Ahmed Essam
*/

#ifndef AM_H_
#define AM_H_

#include "state.h"

typedef enum{
	AM_alarmOFF,
	AM_alarmON,
	AM_waiting
} AM_enum;
extern AM_enum AM_state_id;

STATE_def(AM_alarmOFF);
STATE_def(AM_alarmON);
STATE_def(AM_waiting);

extern void (*AM_state)();

#endif /* AM_H_ */