#pragma once
#ifndef _CAL_MATH_H 
#define _CAL_MATH_H 
#include "stm32f10x.h"
double f(double x);//模拟函数表达式
void Getexpression();//得到函数表达式
double trapezoidal_rule(double a, double b, int n);//定义法求积分
double intergral();//定积分配置
#endif