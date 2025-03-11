#include "OLED_UI.h"
#include "OLED_UI_MenuData.h"
int main(){
	
	OLED_UI_Init(&MainMenuPage);

	while(1){

		OLED_UI_MainLoop();

	}
}


void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		OLED_UI_InterruptHandler();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
