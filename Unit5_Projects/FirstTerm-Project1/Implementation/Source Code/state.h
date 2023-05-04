/*
 * state.h
 *
 *  Created on: Mar 19, 2023
 *  Eng. Ahmed Essam
 */

#ifndef STATE_H_
#define STATE_H_

//State function generator
#define STATE_def(_stateFun_) void State_##_stateFun_()
#define STATE(_stateFun_) State_##_stateFun_

//Triggered signals interface
void setPressureVal(int pVal);
void highPressureFlag();
void startAlarm();
void stopAlarm();

#endif /* STATE_H_ */
