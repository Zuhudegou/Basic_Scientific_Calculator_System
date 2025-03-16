#include "OLED_UI_MenuData.h"
#include "OLED_UI.h"

/*此文件用于存放菜单数据。实际上菜单数据可以存放在任何地方，存放于此处是为了规范与代码模块化*/

// ColorMode 是一个在OLED_UI当中定义的bool类型变量，用于控制OLED显示的颜色模式， DARKMODE 为深色模式， LIGHTMOOD 为浅色模式。这里将其引出是为了创建单选框菜单项。
// OLED_UI_Brightness 是一个在OLED_UI当中定义的int16_t类型变量，用于控制OLED显示的亮度。这里将其引出是为了创建调整亮度的滑动条窗口，范围0-255。
extern int16_t OLED_UI_Brightness;
static float Calfloatnum = 0.0;
static int32_t Calintnum = 0;
static float Calsecfloatnum = 0.0;
static int32_t Calsecintnum = 0;


OperatorType currentOperator = OP_NONE; // 初始未选择
#define SPEED 10

//关于窗口的结构体
MenuWindow SetBrightnessWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.Text_String = "屏幕亮度",					//窗口标题
	.Text_FontSize = OLED_UI_FONT_12,				//字高
	.Text_FontSideDistance = 4,							//字体距离左侧的距离
	.Text_FontTopDistance = 3,							//字体距离顶部的距离
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间

	.Prob_Data_Int_16 = &OLED_UI_Brightness,				//显示的变量地址
	.Prob_DataStep = 5,								//步长
	.Prob_MinData = 5,									//最小值
	.Prob_MaxData = 255, 								//最大值
	.Prob_BottomDistance = 3,							//底部间距
	.Prob_LineHeight = 8,								//进度条高度
	.Prob_SideDistance = 4,								//边距
};
/**
 * @brief 创建显示亮度窗口
 */
void BrightnessWindow(void){
	OLED_UI_CreateWindow(&SetBrightnessWindow);
}
MenuWindow NullWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间
};
/**
 * @brief 创建显示亮度窗口
 */
void EmptyWindow(void){
	OLED_UI_CreateWindow(&NullWindow);
}
MenuWindow FirstFloatNumberWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.Text_String = "The First Number",					//窗口标题
	.Text_FontSize = OLED_UI_FONT_12,				//字高
	.Text_FontSideDistance = 4,							//字体距离左侧的距离
	.Text_FontTopDistance = 3,							//字体距离顶部的距离
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间

	.Prob_Data_Float = &Calfloatnum,				//显示的变量地址
	.Prob_DataStep = 0.01,								//步长
	.Prob_MinData = -255,									//最小值
	.Prob_MaxData = 255, 								//最大值
	.Prob_BottomDistance = 3,							//底部间距
	.Prob_LineHeight = 8,								//进度条高度
	.Prob_SideDistance = 4,								//边距
};

void ShowFirstFloatNumberWindow(void){
	OLED_UI_CreateWindow(&FirstFloatNumberWindow);
}

MenuWindow FirstIntNumberWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.Text_String = "The First Number",					//窗口标题
	.Text_FontSize = OLED_UI_FONT_12,				//字高
	.Text_FontSideDistance = 4,							//字体距离左侧的距离
	.Text_FontTopDistance = 3,							//字体距离顶部的距离
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间

	.Prob_Data_Int_32 = &Calintnum,				//显示的变量地址
	.Prob_DataStep = 1,								//步长
	.Prob_MinData = -1000,									//最小值
	.Prob_MaxData = 1000, 								//最大值
	.Prob_BottomDistance = 3,							//底部间距
	.Prob_LineHeight = 8,								//进度条高度
	.Prob_SideDistance = 4,								//边距
};

void ShowFirstIntNumberWindow(void){
	OLED_UI_CreateWindow(&FirstIntNumberWindow);
}
MenuWindow SecondFloatNumberWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.Text_String = "The Second Number",					//窗口标题
	.Text_FontSize = OLED_UI_FONT_12,				//字高
	.Text_FontSideDistance = 4,							//字体距离左侧的距离
	.Text_FontTopDistance = 3,							//字体距离顶部的距离
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间

	.Prob_Data_Float = &Calsecfloatnum,				//显示的变量地址
	.Prob_DataStep = 0.01,								//步长
	.Prob_MinData = -255,									//最小值
	.Prob_MaxData = 255, 								//最大值
	.Prob_BottomDistance = 3,							//底部间距
	.Prob_LineHeight = 8,								//进度条高度
	.Prob_SideDistance = 4,								//边距
};

void ShowSecondFloatNumberWindow(void){
	OLED_UI_CreateWindow(&SecondFloatNumberWindow);
}

MenuWindow SecondIntNumberWindow = {
	.General_Width = 80,								//窗口宽度
	.General_Height = 28, 							//窗口高度
	.Text_String = "The Second Number",					//窗口标题
	.Text_FontSize = OLED_UI_FONT_12,				//字高
	.Text_FontSideDistance = 4,							//字体距离左侧的距离
	.Text_FontTopDistance = 3,							//字体距离顶部的距离
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//窗口类型
	.General_ContinueTime = 4.0,						//窗口持续时间

	.Prob_Data_Int_32 = &Calsecintnum,				//显示的变量地址
	.Prob_DataStep = 1,								//步长
	.Prob_MinData = -1000,									//最小值
	.Prob_MaxData = 1000, 								//最大值
	.Prob_BottomDistance = 3,							//底部间距
	.Prob_LineHeight = 8,								//进度条高度
	.Prob_SideDistance = 4,								//边距
};

void ShowSecondIntNumberWindow(void){
	OLED_UI_CreateWindow(&SecondIntNumberWindow);
}


//关于窗口的结构体
//主菜单的菜单项
MenuItem MainMenuItems[] = {

	{.General_item_text = "设置",.General_callback = NULL,.General_SubMenuPage = &SettingsMenuPage,.Tiles_Icon = Image_setings},
	{.General_item_text = "计算器",.General_callback = NULL,.General_SubMenuPage = &CalculatorMenuPage,.Tiles_Icon = Image_calc},
	{.General_item_text = "坤分",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_calc},
	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/

};
//设置菜单项内容数组
MenuItem SettingsMenuItems[] = {
	{.General_item_text = "亮度",.General_callback = BrightnessWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "此设备",.General_callback = NULL,.General_SubMenuPage = &AboutThisDeviceMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "关于Calculator",.General_callback = NULL,.General_SubMenuPage = &AboutOLED_UIMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "[返回]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/
};

MenuItem AboutThisDeviceMenuItems[] = {
	{.General_item_text = " STM32F103",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " RAM:20KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " ROM:64KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SSD1306 128x64 OLED",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[返回]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/
};

MenuItem AboutOLED_UIMenuItems[] = {
	{.General_item_text = "https://github.com/Zuhudegou",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[返回]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/
};

MenuItem CalculatorMenuItems[] = {
	{.General_item_text = "Float First Number",.General_callback = ShowFirstFloatNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Int First Number",.General_callback = ShowFirstIntNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Select an operator",.General_callback = NULL,.General_SubMenuPage =&About_OperatorMenuPage,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/
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
	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/

};
MenuItem CalculatorSecondMenuItems[] = {
	{.General_item_text = "Float Second Number",.General_callback = ShowSecondFloatNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Int Second Number",.General_callback = ShowSecondIntNumberWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "Get answers",.General_callback = NULL,.General_SubMenuPage =NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*最后一项的General_item_text置为NULL，表示该项为分割线*/
};





MenuPage MainMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_TILES,  		 //菜单类型为磁贴类型
	.General_CursorStyle = NOT_SHOW,			 //光标类型
	.General_FontSize = OLED_UI_FONT_16,			//字高
	.General_ParentMenuPage = NULL,				//由于这是根菜单，所以父菜单为NULL
	.General_LineSpace = 5,						//磁贴间距 单位：像素（对于磁贴类型菜单，此值表示每个磁贴之间的间距，对于列表类型菜单，此值表示行间距）
	.General_MoveStyle = UNLINEAR,				//移动方式
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = MainMenuItems,			//菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.Tiles_ScreenHeight = 64,					//屏幕高度
	.Tiles_ScreenWidth = 128,						//屏幕宽度
	.Tiles_TileWidth = 32,						 //磁贴宽度
	.Tiles_TileHeight = 32,						 //磁贴高度
};

MenuPage CalculatorMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //光标类型为线型
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &MainMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = CalculatorMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = true,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标
};


MenuPage SettingsMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //光标类型为线型
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &MainMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = SettingsMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = true,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标
};

MenuPage AboutThisDeviceMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_BLOCK,	 //光标类型为圆角矩形
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &SettingsMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = AboutThisDeviceMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = false,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标

};

MenuPage AboutOLED_UIMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_BLOCK,	 //光标类型为圆角矩形
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &SettingsMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = AboutOLED_UIMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = false,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标

};
MenuPage  About_OperatorMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_BLOCK,	 //光标类型为圆角矩形
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &CalculatorMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = About_OperatorMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = false,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标

};
MenuPage CalculatorSecondMenuPage = {
	//通用属性，必填
	.General_MenuType = MENU_TYPE_LIST,  		 //菜单类型为列表类型
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //光标类型为线型
	.General_FontSize = OLED_UI_FONT_12,			//字高
	.General_ParentMenuPage = &CalculatorMenuPage,		 //父菜单为主菜单
	.General_LineSpace = 4,						//行间距 单位：像素
	.General_MoveStyle = UNLINEAR,				//移动方式为非线性曲线动画
	.General_MovingSpeed = SPEED,					//动画移动速度(此值根据实际效果调整)
	.General_MenuItems = CalculatorSecondMenuItems,		 //菜单项内容数组

	//特殊属性，根据.General_MenuType的类型选择
	.List_MenuArea = {1, 1, 128, 64},			 //列表显示区域
	.List_IfDrawFrame = false,					 //是否显示边框
	.List_IfDrawLinePerfix = true,				 //是否显示行前缀
	.List_StartPointX = 4,                        //列表起始点X坐标
	.List_StartPointY = 2,                        //列表起始点Y坐标
};

