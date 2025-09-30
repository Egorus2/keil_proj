#include "stm32f4xx.h"                  // Device header
#include "system_stm32f4xx.h"

//privat func include
#include "init_file.h"
#include "INT_Handler.h"

//privat variables
static uint16_t startTime;

int main(void)
{
	RCC_Init();
	GPIO_init();
	sysTickInit();
	
	
	while(1)
	{
		startTime = (uint16_t)msCounter;
		while(msCounter - startTime < 1000);
		GPIOA->ODR ^= GPIO_ODR_OD5;
	}
}



