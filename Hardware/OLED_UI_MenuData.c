#include "OLED_UI_MenuData.h"
#include "OLED_UI.h"

extern bool ColorMode;
extern bool OLED_UI_ShowFps;
// OLED_UI_Brightness ???????OLED_UI????????int16_t????????????????OLED??????????????????????????????????????????????????0-255??
extern int16_t OLED_UI_Brightness;
float testfloatnum = 0.5;
int32_t testintnum = 1;
#define SPEED 10

//???????????
MenuWindow SetBrightnessWindow = {
	.General_Width = 80,								//??????
	.General_Height = 28, 							//??????
	.Text_String = "??????????????",					//???????
	.Text_FontSize = OLED_UI_FONT_12,				//???
	.Text_FontSideDistance = 4,							//??????????????
	.Text_FontTopDistance = 3,							//??????????????
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//????????
	.General_ContinueTime = 4.0,						//??????????

	.Prob_Data_Int_16 = &OLED_UI_Brightness,				//???????????
	.Prob_DataStep = 5,								//????
	.Prob_MinData = 5,									//????
	.Prob_MaxData = 255, 								//????
	.Prob_BottomDistance = 3,							//??????
	.Prob_LineHeight = 8,								//?????????
	.Prob_SideDistance = 4,								//???
};
/**
 * @brief ??????????????
 */
void BrightnessWindow(void){
	OLED_UI_CreateWindow(&SetBrightnessWindow);
}
//???????????
MenuWindow NullWindow = {
	.General_Width = 80,								//??????
	.General_Height = 28, 							//??????
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//????????
	.General_ContinueTime = 4.0,						//??????????
};
/**
 * @brief ??????????????
 */
void EmptyWindow(void){
	OLED_UI_CreateWindow(&NullWindow);
}
//???????????
MenuWindow TextWindow = {
	.General_Width = 75,								//??????
	.General_Height = 18, 							//??????
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//????????
	.General_ContinueTime = 4.0,						//??????????

	.Text_String = "????text",					//???????
	.Text_FontSize = OLED_UI_FONT_12,				//???
	.Text_FontSideDistance = 8,							//??????????????
	.Text_FontTopDistance = 2,							//??????????????
	

};
/**
 * @brief ??????????????
 */
void ShowTextWindow(void){
	OLED_UI_CreateWindow(&TextWindow);
}
//???????????
MenuWindow FloatDataWindow = {
	.General_Width = 80,								//??????
	.General_Height = 28, 							//??????
	.Text_String = "???????????",					//???????
	.Text_FontSize = OLED_UI_FONT_12,				//???
	.Text_FontSideDistance = 4,							//??????????????
	.Text_FontTopDistance = 3,							//??????????????
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//????????
	.General_ContinueTime = 4.0,						//??????????

	.Prob_Data_Float = &testfloatnum,				//???????????
	.Prob_DataStep = 0.1,								//????
	.Prob_MinData = -100,									//????
	.Prob_MaxData = 100, 								//????
	.Prob_BottomDistance = 3,							//??????
	.Prob_LineHeight = 8,								//?????????
	.Prob_SideDistance = 4,	
};
/**
 * @brief ??????????????
 */
void ShowFloatDataWindow(void){
	OLED_UI_CreateWindow(&FloatDataWindow);
}
//???????????
MenuWindow IntDataWindow = {
	.General_Width = 80,								//??????
	.General_Height = 28, 							//??????
	.Text_String = "???????????",					//???????
	.Text_FontSize = OLED_UI_FONT_12,				//???
	.Text_FontSideDistance = 4,							//??????????????
	.Text_FontTopDistance = 3,							//??????????????
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//????????
	.General_ContinueTime = 4.0,						//??????????

	.Prob_Data_Int_32 = &testintnum,				//???????????
	.Prob_DataStep = 1,								//????
	.Prob_MinData = -100,									//????
	.Prob_MaxData = 100, 								//????
	.Prob_BottomDistance = 3,							//??????
	.Prob_LineHeight = 8,								//?????????
	.Prob_SideDistance = 4,	
};
/**
 * @brief ??????????????
 */
void ShowIntDataWindow(void){
	OLED_UI_CreateWindow(&IntDataWindow);
}
//??LOGO????????
OLED_ChangePoint LogoMove;
//??LOGO????????????
OLED_ChangePoint LogoTextMove;
//welcome????????????
OLED_ChangePoint WelcomeTextMove;

extern OLED_ChangePoint OLED_UI_PageStartPoint ;



//???????????????????
void SettingAuxFunc(void){
	//?????????LOGO
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		LogoMove.TargetPoint.X = 0;
		LogoMove.TargetPoint.Y = 0;
	}
	//??LOGOTEXT???????????????????
	LogoTextMove.TargetPoint.X = 129;
	LogoTextMove.TargetPoint.Y = 0;
	//??Welcome?????????????????????????
	WelcomeTextMove.TargetPoint.X = 128;
	WelcomeTextMove.TargetPoint.Y = 0;
	ChangePoint(&LogoMove);
	OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	ChangePoint(&LogoTextMove);
	OLED_ShowImageArea(LogoTextMove.CurrentPoint.X,LogoTextMove.CurrentPoint.Y,26,64,0,0,128,128,OLED_UI_LOGOTEXT64);
	ChangePoint(&WelcomeTextMove);
//	OLED_ShowImageArea(WelcomeTextMove.CurrentPoint.X,WelcomeTextMove.CurrentPoint.Y,16,64,0,0,128,128,OLED_UI_LOGOGithub);
}

void AboutThisDeviceAuxFunc(void){
	//??LOGO?????????????????????
	LogoMove.TargetPoint.X = 0;
	LogoMove.TargetPoint.Y = -80;
	ChangePoint(&LogoMove);
    OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	//???????????LOGO????
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		LogoTextMove.TargetPoint.X = 102;
		LogoTextMove.TargetPoint.Y = 0;
	}
	ChangePoint(&LogoTextMove);
	OLED_ShowImageArea(LogoTextMove.CurrentPoint.X,LogoTextMove.CurrentPoint.Y,26,64,0,0,128,128,OLED_UI_LOGOTEXT64);
}
//????OLED UI????????????
void AboutOLED_UIAuxFunc(void){
	
	LogoMove.TargetPoint.X = 0;
	LogoMove.TargetPoint.Y = -80;
	ChangePoint(&LogoMove);
	OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		WelcomeTextMove.TargetPoint.X = 110;
		WelcomeTextMove.TargetPoint.Y = 0;
	}
	ChangePoint(&WelcomeTextMove);
	OLED_ShowImageArea(WelcomeTextMove.CurrentPoint.X,WelcomeTextMove.CurrentPoint.Y,16,64,0,0,128,128,OLED_UI_LOGOGithub);

}

void MainAuxFunc(void){
	
	LogoMove.TargetPoint.X = -200;
	LogoMove.TargetPoint.Y = 0;
	LogoMove.CurrentPoint.X = -200;
	LogoMove.CurrentPoint.Y = 0;

	LogoTextMove.TargetPoint.X = 129;
	LogoTextMove.TargetPoint.Y = 0;
	LogoTextMove.CurrentPoint.X = 129;
	LogoTextMove.CurrentPoint.Y = 0;
	
	WelcomeTextMove.TargetPoint.X = 128;
	WelcomeTextMove.TargetPoint.Y = 0;
	WelcomeTextMove.CurrentPoint.X = 128;
	WelcomeTextMove.CurrentPoint.Y = 0;
}


MenuItem MainMenuItems[] = {

	{.General_item_text = "????",.General_callback = NULL,.General_SubMenuPage = &SettingsMenuPage,.Tiles_Icon = Image_setings},
	{.General_item_text = "??????",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_calc},
	{.General_item_text = "????",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_calc},
	{.General_item_text = "?????",.General_callback = NULL,.General_SubMenuPage = &MoreMenuPage,.Tiles_Icon = Image_more},
	{.General_item_text = NULL},

};
MenuItem SettingsMenuItems[] = {
	{.General_item_text = "????",.General_callback = BrightnessWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "?????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = &ColorMode},
	{.General_item_text = "??????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = &OLED_UI_ShowFps},
	{.General_item_text = "????",.General_callback = NULL,.General_SubMenuPage = &AboutThisDeviceMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "?????Calculator",.General_callback = NULL,.General_SubMenuPage = &AboutOLED_UIMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},
};

MenuItem AboutThisDeviceMenuItems[] = {
	{.General_item_text = " STM32F103",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " RAM:20KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " ROM:64KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SSD1306 128x64 OLED",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SoftWare i2c",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem AboutOLED_UIMenuItems[] = {
	{.General_item_text = " https://github.com/Zuhudegou",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem MoreMenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????8demo",.General_callback = NULL,.General_SubMenuPage = &Font8MenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????12demo",.General_callback = NULL,.General_SubMenuPage = &Font12MenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????16demo",.General_callback = NULL,.General_SubMenuPage = &Font16MenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????20demo",.General_callback = NULL,.General_SubMenuPage = &Font20MenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????demo",.General_callback = NULL,.General_SubMenuPage = &LongMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????demo",.General_callback = NULL,.General_SubMenuPage = &SpringMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????????demo",.General_callback = NULL,.General_SubMenuPage = &LongListMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "?????????demo",.General_callback = NULL,.General_SubMenuPage = &SmallAreaMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "?????demo",.General_callback = EmptyWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????demo",.General_callback = ShowTextWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "????????????????demo",.General_callback = ShowFloatDataWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????????????demo",.General_callback = ShowIntDataWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};
MenuItem Font8MenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem Font12MenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem Font16MenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem Font20MenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem LongMenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "??????????????????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Very Very Very Long English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem SpringMenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem LongListMenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item1",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item2",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item3",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item4",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item5",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item6",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item7",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item8",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item9",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item10",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item11",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item12",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item13",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item14",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item15",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item16",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item17",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item18",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item19",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item20",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item21",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item22",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item23",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item24",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item25",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item26",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item27",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item28",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item29",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item30",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item31",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item32",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item33",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item34",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item35",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item36",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item37",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item38",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item39",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item40",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item41",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item42",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item43",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item44",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item45",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item46",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item47",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item48",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item49",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item50",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item51",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item52",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item53",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item54",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item55",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item56",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item57",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item58",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item59",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item60",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item61",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item62",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item63",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item64",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item65",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item66",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item67",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item68",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item69",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item70",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item71",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item72",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item73",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item74",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item75",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item76",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item77",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item78",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item79",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item80",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item81",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item82",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item83",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item84",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item85",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},	
	{.General_item_text = "Item86",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item87",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item88",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item89",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item90",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item91",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item92",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item93",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item94",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item95",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item96",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item97",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item98",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item99",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item100",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item101",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item102",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item103",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item104",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item105",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item106",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item107",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item108",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item109",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item110",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item111",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item112",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item113",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item114",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item115",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item116",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item117",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item118",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item119",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item120",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item121",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item122",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item123",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item124",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item125",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item126",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item127",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item128",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Item129",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};

MenuItem SmallAreaMenuItems[] = {
	{.General_item_text = "[????]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "???????",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "English Text",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "1234567890",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "abcdefghijklmnopqrstuvwxyz",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = ",.[]!@#$+-/^&*()",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*???????General_item_text???NULL???????????????*/
};



MenuPage MainMenuPage = {
	
	.General_MenuType = MENU_TYPE_TILES,  		 //????????????????
	.General_CursorStyle = NOT_SHOW,			 //???????
	.General_FontSize = OLED_UI_FONT_16,			//???
	.General_ParentMenuPage = NULL,				//???????????????????????NULL
	.General_LineSpace = 5,						//??????? ?????????????????????????????????????????????????????????????????????
	.General_MoveStyle = UNLINEAR,				//??????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = MainAuxFunc,		 //???????????
	.General_MenuItems = MainMenuItems,			//?????????????

	//?????????????.General_MenuType?????????
	.Tiles_ScreenHeight = 64,					//??????
	.Tiles_ScreenWidth = 128,						//??????
	.Tiles_TileWidth = 32,						 //???????
	.Tiles_TileHeight = 32,						 //???????
};


MenuPage SettingsMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MainMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = SettingAuxFunc,		 //???????????
	.General_MenuItems = SettingsMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {32, 0, 95, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????
};

MenuPage AboutThisDeviceMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_BLOCK,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &SettingsMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = AboutThisDeviceAuxFunc,		 //???????????
	.General_MenuItems = AboutThisDeviceMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 100, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = false,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage AboutOLED_UIMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_BLOCK,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &SettingsMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = AboutOLED_UIAuxFunc,		 //???????????
	.General_MenuItems = AboutOLED_UIMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 105, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = false,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};
MenuPage MoreMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MainMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = MoreMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {1, 1, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage Font8MenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_8,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 5,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = Font8MenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage Font12MenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = Font12MenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage Font16MenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_16,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 5,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = Font16MenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {1, 1, 126, 62},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage Font20MenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_20,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 10,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = Font20MenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage LongMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = LongMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage SpringMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = PID_CURVE,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = SpringMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage LongListMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 4,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = LongListMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {0, 0, 128, 64},			 //??????????
	.List_IfDrawFrame = false,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

MenuPage SmallAreaMenuPage = {
	//????????????
	.General_MenuType = MENU_TYPE_LIST,  		 //???????????????
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //??????????????
	.General_FontSize = OLED_UI_FONT_12,			//???
	.General_ParentMenuPage = &MoreMenuPage,		 //???????????
	.General_LineSpace = 6,						//???? ?????????
	.General_MoveStyle = UNLINEAR,				//????????????????????
	.General_MovingSpeed = SPEED,					//??????????(?????????????????)
	.General_ShowAuxiliaryFunction = NULL,		 //???????????
	.General_MenuItems = SmallAreaMenuItems,		 //?????????????

	//?????????????.General_MenuType?????????
	.List_MenuArea = {10, 10, 60, 36},			 //??????????
	.List_IfDrawFrame = true,					 //?????????
	.List_IfDrawLinePerfix = true,				 //??????????
	.List_StartPointX = 4,                        //????????X????
	.List_StartPointY = 2,                        //????????Y????

};

