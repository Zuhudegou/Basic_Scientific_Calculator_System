#include "bsp_encoder.h"
#include "bsp_key.h"
void Encoder_Init(void)
{
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);
	
	TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_Cmd(TIM1, ENABLE);
	
	TIM_SetCounter(TIM1, 0);
}


void Encoder_Enable(void)
{
	TIM_Cmd(TIM1, ENABLE);
}

void Encoder_Disable(void)
{
	TIM_Cmd(TIM1, DISABLE);
}

int16_t Encoder_Get(void)
{
    // 静态变量，用于在函数调用间保存未被4整除的余数
    static int32_t encoderAccumulator = 0;
    
    // 读取当前定时器计数值
    int16_t temp = TIM_GetCounter(TIM1);
    
    // 清零定时器计数器，为下次读取做准备
    TIM_SetCounter(TIM1, 0);
    
    // 将当前读取值累加到累加器中
    encoderAccumulator += temp;
    
    // 计算四倍频解码后的增量值（去除未完成的部分）
    int16_t result = encoderAccumulator / 4;
    
    // 保存未被4整除的余数，保证精度
    encoderAccumulator %= 4;
    
    // 返回解码后的增量值
    return result;
}
