
#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	unsigned char i, j, k;
	DDRC = 0xff;
	
	while (1)
	{
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				for(k = 0; k < 10; k++){
					PORTC = 0b1101 | (i<<4);
					_delay_ms(50);
					PORTC = 0b0111 | (j<<4);
					_delay_ms(50);
				}
			}
		}
	}
}

