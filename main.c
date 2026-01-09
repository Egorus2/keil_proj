#include "stm32f4xx.h"                  // Device header
#include "system_stm32f4xx.h"

//privat func include
#include "init_file.h"
#include "sysTick_init.h"

//privat variables
static uint64_t startTime;

int main(void)
{
	RCC_Init();
	GPIO_init();
	sysTickInit();
	
	
	while(1)
	{
		startTime = msCounter;
		while(msCounter - startTime < 800);
		GPIOA->ODR ^= GPIO_ODR_OD5;
	}
}



