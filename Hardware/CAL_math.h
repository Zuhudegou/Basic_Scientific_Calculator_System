#pragma once
#ifndef _CAL_MATH_H 
#define _CAL_MATH_H 
#include "stm32f10x.h"

int64_t CAL_intadd(int64_t num1,int64_t num2);
int64_t CAL_intsub(int64_t num1,int64_t num2);
int64_t CAL_intmul(int64_t num1,int64_t num2);
int64_t CAL_intdiv(int64_t num1,int64_t num2);
float CAL_floatadd(float num1,float num2);
float CAL_floatsub(float num1,float num2);
float CAL_floatmul(float num1,float num2);
float CAL_floatdiv(float num1,float num2);

#endif 

