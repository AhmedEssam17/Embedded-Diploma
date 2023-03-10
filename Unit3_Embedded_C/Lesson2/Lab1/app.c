#include "uart.h"

unsigned char gBuffer[100] = "learn-in-depth: Ahmed Essam";
unsigned char const gBuffer2[100] = "learn-in-depth: Ahmed Essam";

void main(){
	Uart_Send_String(gBuffer);
}
