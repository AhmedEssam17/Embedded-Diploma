#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "PressureSensorDriver.h"
#include "ComparingAlgorithm.h"
#include "AlarmMonitor.h"
#include "AlarmActuatorDriver.h"

int main (){

	GPIO_INITIALIZATION();
	PSD_state = STATE(PSD_reading);
	CA_state = STATE(CA_waiting);
	AM_state = STATE(AM_alarmOFF);
	AAD_state = STATE(AAD_waiting);

	while (1)
	{
		PSD_state();
		CA_state();
		AM_state();
		AAD_state();
	}

}
