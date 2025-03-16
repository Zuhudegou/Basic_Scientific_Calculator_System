#ifndef __OLED_UI_DRIVER_H
#define __OLED_UI_DRIVER_H
/*【如果您需要移植此项目，则需要更改以下函数的实现方式。】 */
#include "stm32f10x.h"                  // Device header


void Delay_us(uint32_t xus);
void Delay_ms(uint32_t xms);
void Delay_s(uint32_t xs);

#endif
