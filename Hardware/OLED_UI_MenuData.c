#include "OLED_UI_MenuData.h"
#include "OLED_UI.h"

/*���ļ����ڴ�Ų˵����ݡ�ʵ���ϲ˵����ݿ��Դ�����κεط�������ڴ˴���Ϊ�˹淶�����ģ�黯*/

// ColorMode ��һ����OLED_UI���ж����bool���ͱ��������ڿ���OLED��ʾ����ɫģʽ�� DARKMODE Ϊ��ɫģʽ�� LIGHTMOOD Ϊǳɫģʽ�����ｫ��������Ϊ�˴�����ѡ��˵��
// OLED_UI_Brightness ��һ����OLED_UI���ж����int16_t���ͱ��������ڿ���OLED��ʾ�����ȡ����ｫ��������Ϊ�˴����������ȵĻ��������ڣ���Χ0-255��
extern int16_t OLED_UI_Brightness;
static float Calfloatnum = 0.0;
static int32_t Calintnum = 0;
static float Calsecfloatnum = 0.0;
static int32_t Calsecintnum = 0;


OperatorType currentOperator = OP_NONE; // ��ʼδѡ��
#define SPEED 10

//���ڴ��ڵĽṹ��
MenuWindow SetBrightnessWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��Ļ����",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_16 = &OLED_UI_Brightness,				//��ʾ�ı�����ַ
	.Prob_DataStep = 5,								//����
	.Prob_MinData = 5,									//��Сֵ
	.Prob_MaxData = 255, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
};
/**
 * @brief ������ʾ���ȴ���
 */
void BrightnessWindow(void){
	OLED_UI_CreateWindow(&SetBrightnessWindow);
}
MenuWindow NullWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��
};
/**
 * @brief ������ʾ���ȴ���
 */
void EmptyWindow(void){
	OLED_UI_CreateWindow(&NullWindow);
}
MenuWindow FirstFloatNumberWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "The First Number",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Float = &Calfloatnum,				//��ʾ�ı�����ַ
	.Prob_DataStep = 0.01,								//����
	.Prob_MinData = -255,									//��Сֵ
	.Prob_MaxData = 255, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
};

void ShowFirstFloatNumberWindow(void){
	OLED_UI_CreateWindow(&FirstFloatNumberWindow);
}

MenuWindow FirstIntNumberWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "The First Number",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &Calintnum,				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = -1000,									//��Сֵ
	.Prob_MaxData = 1000, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
};

void ShowFirstIntNumberWindow(void){
	OLED_UI_CreateWindow(&FirstIntNumberWindow);
}
MenuWindow SecondFloatNumberWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "The Second Number",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Float = &Calsecfloatnum,				//��ʾ�ı�����ַ
	.Prob_DataStep = 0.01,								//����
	.Prob_MinData = -255,									//��Сֵ
	.Prob_MaxData = 255, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
};

void ShowSecondFloatNumberWindow(void){
	OLED_UI_CreateWindow(&SecondFloatNumberWindow);
}

MenuWindow SecondIntNumberWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "The Second Number",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &Calsecintnum,				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = -1000,									//��Сֵ
	.Prob_MaxData = 1000, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
};

void ShowSecondIntNumberWindow(void){
	OLED_UI_CreateWindow(&SecondIntNumberWindow);
}


//���ڴ��ڵĽṹ��
//���˵��Ĳ˵���
MenuItem MainMenuItems[] = {

	{.General_item_text = "����",.General_callback = NULL,.General_SubMenuPage = &SettingsMenuPage,.Tiles_Icon = Image_setings},
	{.General_item_text = "������",.General_callback = NULL,.General_SubMenuPage = &CalculatorMenuPage,.Tiles_Icon = Image_calc},
	{.General_item_text = "����",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_calc},
	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/

};
//���ò˵�����������
MenuItem SettingsMenuItems[] = {
	{.General_item_text = "����",.General_callback = BrightnessWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "���豸",.General_callback = NULL,.General_SubMenuPage = &AboutThisDeviceMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "����Calculator",.General_callback = NULL,.General_SubMenuPage = &AboutOLED_UIMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

MenuItem AboutThisDeviceMenuItems[] = {
	{.General_item_text = " STM32F103",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " RAM:20KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " ROM:64KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SSD1306 128x64 OLED",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

MenuItem AboutOLED_UIMenuItems[] = {
	{.General_item_text = "https://github.com/Zuhudegou",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

MenuItem CalculatorMenuItems[] = {
	{.General_item_text = "Float First Number",.General_callback = ShowFirstFloatNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Int First Number",.General_callback = ShowFirstIntNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Select an operator",.General_callback = NULL,.General_SubMenuPage =&About_OperatorMenuPage,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

void OnPlusSelected() {
    currentOperator = OP_PLUS;
}

void OnSubtractSelected() {
    currentOperator = OP_SUBTRACT;
}

void OnMultiplySelected() {
    currentOperator = OP_MULTIPLY;
}

void OnDivideSelected() {
    currentOperator = OP_DIVIDE;
}
MenuItem About_OperatorMenuItems[] = {
	{.General_item_text = "Plus", .General_callback = OnPlusSelected, .General_SubMenuPage = &CalculatorSecondMenuPage, .List_BoolRadioBox = NULL},
	{.General_item_text = "Subtract", .General_callback = OnSubtractSelected, .General_SubMenuPage = &CalculatorSecondMenuPage, .List_BoolRadioBox = NULL},
	{.General_item_text = "Multiply", .General_callback = OnMultiplySelected, .General_SubMenuPage = &CalculatorSecondMenuPage, .List_BoolRadioBox = NULL},
	{.General_item_text = "Divide", .General_callback = OnDivideSelected, .General_SubMenuPage = &CalculatorSecondMenuPage, .List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/

};
MenuItem CalculatorSecondMenuItems[] = {
	{.General_item_text = "Float Second Number",.General_callback = ShowSecondFloatNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Int Second Number",.General_callback = ShowSecondIntNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Get answers",.General_callback = NULL,.General_SubMenuPage =NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};





MenuPage MainMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_TILES,  		 //�˵�����Ϊ��������
	.General_CursorStyle = NOT_SHOW,			 //�������
	.General_FontSize = OLED_UI_FONT_16,			//�ָ�
	.General_ParentMenuPage = NULL,				//�������Ǹ��˵������Ը��˵�ΪNULL
	.General_LineSpace = 5,						//������� ��λ�����أ����ڴ������Ͳ˵�����ֵ��ʾÿ������֮��ļ�࣬�����б����Ͳ˵�����ֵ��ʾ�м�ࣩ
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽ
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = MainMenuItems,			//�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.Tiles_ScreenHeight = 64,					//��Ļ�߶�
	.Tiles_ScreenWidth = 128,						//��Ļ���
	.Tiles_TileWidth = 32,						 //�������
	.Tiles_TileHeight = 32,						 //�����߶�
};

MenuPage CalculatorMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //�������Ϊ����
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &MainMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = CalculatorMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = true,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����
};


MenuPage SettingsMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //�������Ϊ����
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &MainMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = SettingsMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = true,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����
};

MenuPage AboutThisDeviceMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_BLOCK,	 //�������ΪԲ�Ǿ���
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &SettingsMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = AboutThisDeviceMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = false,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����

};

MenuPage AboutOLED_UIMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_BLOCK,	 //�������ΪԲ�Ǿ���
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &SettingsMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = AboutOLED_UIMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = false,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����

};
MenuPage  About_OperatorMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_BLOCK,	 //�������ΪԲ�Ǿ���
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &CalculatorMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = About_OperatorMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = false,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����

};
MenuPage CalculatorSecondMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //�������Ϊ����
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &CalculatorMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_MenuItems = CalculatorSecondMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {1, 1, 128, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = true,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����
};

