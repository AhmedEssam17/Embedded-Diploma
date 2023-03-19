/*
 * state.h
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

//State function generator
#define STATE_def(_stateFun_) void State_##_stateFun_()
#define STATE(_stateFun_) State_##_stateFun_

//Triggered signals interface
void US_set_distance(int distance);
void DC_set_speed(int speed);

#endif /* STATE_H_ */
