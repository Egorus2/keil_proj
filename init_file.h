#ifndef INIT_FILE_H
#define INIT_FILE_H

#include "stm32f4xx.h"                  // Device header

//privat defines
#define PLLM 25UL
#define PLLN 336UL
#define AHB_FREQ 84000000UL

//privat variables
extern volatile uint64_t msCounter;

//privat func declaration
void RCC_Init(void);
void GPIO_init(void);
void sysTickInit(void);

#endif
