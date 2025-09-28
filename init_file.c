#include "init_file.h"

void RCC_Init(void)
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
	
	//GPIO RCC CONFIG//
	
	//enable GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//set gpio 5 as output
	GPIOA->MODER |= (1 << GPIO_MODER_MODE5_Pos);
	
}
