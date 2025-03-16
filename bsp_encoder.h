#ifndef __bsp_encoder_H
#define __bsp_encoder_H
#include "stm32f10x.h"                  // Device header
void Encoder_Init(void);

void Encoder_Enable(void);

void Encoder_Disable(void);

int16_t Encoder_Get(void);







#endif
