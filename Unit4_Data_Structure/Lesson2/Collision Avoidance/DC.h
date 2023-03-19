/*
 * DC.h
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

typedef enum{
	DC_idle,
	DC_busy
} DC_enum;
extern DC_enum DC_state_id;

void DC_init();

STATE_def(DC_idle);
STATE_def(DC_busy);

extern void (*DC_state)();

#endif /* DC_H_ */
