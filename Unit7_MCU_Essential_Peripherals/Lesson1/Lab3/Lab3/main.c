
#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	
	//DDRD 0 >> input pulldown switch
	ClearBit(DDRD, 0);
	ClearBit(PORTD, 0);
	//PORTD 4,5
	SetBit(DDRD, 4);
	SetBit(DDRD, 5);
	
	while (1)
	{
		if(ReadBit(PIND, 0) == 1){
			SetBit(PORTD, 4);
			SetBit(PORTD, 5);
			_delay_ms(1000);
			ClearBit(PORTD, 4);
			ClearBit(PORTD, 5);
			while(ReadBit(PORTD, 0) == 1);
		}
	}
}

