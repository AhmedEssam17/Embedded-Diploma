/*
	main.c for Cortex-M4
	Eng. Ahmed Essam
*/

#define SYSCTL_BASE 		0x400FE000
#define SYSCTL_RCGC2_R 		*(volatile unsigned long*) (SYSCTL_BASE + 0x108)

#define PORTF_BASE 			0x40025000
#define GPIO_PORTF_DATA_R 	(*(volatile unsigned long*) (PORTF_BASE + 0X3FC))
#define GPIO_PORTF_DIR_R 	(*(volatile unsigned long*) (PORTF_BASE + 0X400))
#define GPIO_PORTF_DEN_R 	(*(volatile unsigned long*) (PORTF_BASE + 0X51C))

int main(void){

	volatile unsigned long delay;

	//Enable GPIO Port
	SYSCTL_RCGC2_R = 0x20;

	//Delay to assure GPIOF is on and running
	for(delay = 0; delay < 200; delay++);

	//Set PF3 direction as output
	GPIO_PORTF_DIR_R |= 1<<3;

	//Enable GPIO pin
	GPIO_PORTF_DEN_R |= 1<<3;

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay = 0; delay < 200000; delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay = 0; delay < 200000; delay++);
	}

	return 0;
}