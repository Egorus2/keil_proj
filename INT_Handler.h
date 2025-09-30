#ifndef INT_HENDLER_H
#define INT_HENDLER_H

#include "stm32f4xx.h"                  // Device header

//privat variables
extern volatile uint64_t msCounter;

//privat func declaration
void SysTick_Handler(void);

#endif
