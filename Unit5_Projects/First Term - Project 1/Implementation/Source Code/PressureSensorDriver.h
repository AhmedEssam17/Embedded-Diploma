/*
	PressureSensorDriver.h
	Eng. Ahmed Essam
*/

#ifndef PSD_H_
#define PSD_H_

#include "state.h"

typedef enum{
	PSD_reading,
	PSD_waiting
} PSD_enum;
extern PSD_enum PSD_state_id;

void pDriver_init();

STATE_def(PSD_reading);
STATE_def(PSD_waiting);

extern void (*PSD_state)();

#endif /* PSD_H_ */