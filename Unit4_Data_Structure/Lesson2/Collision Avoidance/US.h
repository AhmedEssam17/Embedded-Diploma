/*
 * US.h
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#ifndef US_H_
#define US_H_

#include "state.h"

typedef enum{
	US_busy
} US_enum;
extern US_enum US_state_id;

void US_init();

STATE_def(US_busy);

extern void (*US_state)();

#endif /* US_H_ */
