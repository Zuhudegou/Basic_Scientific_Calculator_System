#ifndef __OLED_UI_MENUDATA_H
#define __OLED_UI_MENUDATA_H
#ifdef __cplusplus
extern "C" {
#endif
#include "OLED_UI.h"


extern MenuItem MainMenuItems[],SettingsMenuItems[],AboutThisDeviceMenuItems[],
AboutOLED_UIMenuItems[],CalculatorMenuItems[],About_OperatorMenuItems[],CalculatorSecondMenuItems[];
extern MenuPage MainMenuPage,SettingsMenuPage,AboutThisDeviceMenuPage,
AboutOLED_UIMenuPage,CalculatorMenuPage,About_OperatorMenuPage,CalculatorSecondMenuPage;

typedef enum {
    OP_NONE,
    OP_PLUS,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE
} OperatorType;

OperatorType currentOperator = OP_NONE; // 初始未选择

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
