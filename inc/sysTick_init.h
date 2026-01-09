#ifndef INT_HENDLER_H
#define INT_HENDLER_H

#include "stm32f4xx.h"                  // Device header

//privat define's
#define AHB_FREQ 84000000UL

//privat variables
extern volatile uint64_t msCounter;

//privat func declaration
void sysTickInit(void);
void SysTick_Handler(void);

#endif
