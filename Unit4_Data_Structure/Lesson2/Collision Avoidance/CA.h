/*
 * CA.h
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

typedef enum{
	CA_waiting,
	CA_driving
} CA_enum;
extern CA_enum CA_state_id;

STATE_def(CA_waiting);
STATE_def(CA_driving);

extern void (*CA_state)();

#endif /* CA_H_ */
