
#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    
	//DDRD 5:7 outputs
	DDRD = 0b11100000;
	//PORTD 5:7 >> Output Data Register
	ClearBit(PORTD,5);
	ClearBit(PORTD,6);
	ClearBit(PORTD,7);
	
    while (1) 
    {
		SetBit(PORTD,5);
		_delay_ms(500);
		SetBit(PORTD,6);
		_delay_ms(500);
		SetBit(PORTD,7);
		_delay_ms(500);
		ClearBit(PORTD,7);
		_delay_ms(500);
		ClearBit(PORTD,6);
		_delay_ms(500);
		ClearBit(PORTD,5);
		_delay_ms(500);
    }
}

