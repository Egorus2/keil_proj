#include "sysTick_init.h"

void sysTickInit(void)
/*
 * @brief  Initializing the system clock to operate at a frequency of 1kHz(T = 1 ms)
 * @param  None
 * @retval None
 */
{
	msCounter = 0;
	SysTick->LOAD = (AHB_FREQ/1000) - 1;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Handler(void)
{
	msCounter++;
}
