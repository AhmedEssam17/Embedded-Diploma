/*
	ComparingAlgorithm.h
	Eng. Ahmed Essam
*/

#ifndef CA_H_
#define CA_H_

#include "state.h"

typedef enum{
	CA_detect,
	CA_waiting
} CA_enum;
extern CA_enum CA_state_id;

STATE_def(CA_detect);
STATE_def(CA_waiting);

extern void (*CA_state)();

#endif /* CA_H_ */