#include "init_file.h"

//privat variables
volatile uint64_t msCounter;

void RCC_Init(void)
/*
 * @brief  Initializing RCC settings
 * @param  None
 * @retval None
 * @note When changing the HSE frequency(not 84MHz), the PLL parameters must be changed
 */
{
	RCC->CR |= RCC_CR_HSEON; //external oscillator
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	//disable PLL for setup
	RCC->CR &= ~RCC_CR_PLLON;
	
	// PLL configuration
	RCC->PLLCFGR = (PLLM << RCC_PLLCFGR_PLLM_Pos)|(PLLN << RCC_PLLCFGR_PLLN_Pos)|  
									RCC_PLLCFGR_PLLP_0|RCC_PLLCFGR_PLLSRC_HSE;                        
	
	//PLL on
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	//wait state for flash memory
	do{
		FLASH->ACR |= FLASH_ACR_LATENCY_2WS;
	}while(!(FLASH->ACR & FLASH_ACR_LATENCY_2WS));
	
	//APB1 prescaler
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2|RCC_CFGR_SW_PLL;
	
}

void GPIO_init(void)
{
	//GPIO RCC CONFIG//
	
	//enable GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//set gpio 5 as output
	GPIOA->MODER |= (1 << GPIO_MODER_MODE5_Pos);
	
}


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
