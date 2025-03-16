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
    // ��̬�����������ں������ü䱣��δ��4����������
    static int32_t encoderAccumulator = 0;
    
    // ��ȡ��ǰ��ʱ������ֵ
    int16_t temp = TIM_GetCounter(TIM1);
    
    // ���㶨ʱ����������Ϊ�´ζ�ȡ��׼��
    TIM_SetCounter(TIM1, 0);
    
    // ����ǰ��ȡֵ�ۼӵ��ۼ�����
    encoderAccumulator += temp;
    
    // �����ı�Ƶ����������ֵ��ȥ��δ��ɵĲ��֣�
    int16_t result = encoderAccumulator / 4;
    
    // ����δ��4��������������֤����
    encoderAccumulator %= 4;
    
    // ���ؽ���������ֵ
    return result;
}
