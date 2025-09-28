#ifndef INIT_FILE_H
#define INIT_FILE_H

#include "stm32f4xx.h"                  // Device header

#define PLLM 25UL
#define PLLN 336UL

void RCC_Init(void);

#endif
