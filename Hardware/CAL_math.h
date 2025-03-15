#pragma once
#ifndef _CAL_MATH_H 
#define _CAL_MATH_H 
#include "stm32f10x.h"
long CAL_intadd(long num1,long num2);
long CAL_intsub(long num1,long num2);
long CAL_intmul(long num1,long num2);
long CAL_intdiv(long num1,long num2);
float CAL_floatadd(float num1,float num2);
float CAL_floatsub(float num1,float num2);
float CAL_floatmul(float num1,float num2);
float CAL_floatdiv(float num1,float num2);
void CAL_MATH();
#endif 

