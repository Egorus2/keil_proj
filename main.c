#include "stm32f4xx.h"                  // Device header
#include "system_stm32f4xx.h"

//privat func include
#include "init_file.h"


int main(void)
{
	RCC_Init();
	
	// write 1 to pin
	GPIOA->ODR |= GPIO_ODR_OD5;
	while(1)
	{
		
	}
}



