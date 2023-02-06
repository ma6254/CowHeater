#ifndef BOARD_H
#define BOARD_H

#include "hal_sys.h"

// 调试用LED
// P13
#define LED_GPIO_PORT 1
#define LED_GPIO_BIT 3

// 可控硅光耦控制
// P10
#define HEAT_GPIO_PORT GPIO_P1
#define HEAT_GPIO_BIT 0

// 加热板温度，热电偶信号采样
// P11
#define TEMP_GPIO_PORT GPIO_P1
#define TEMP_GPIO_BIT 1

// 冷端温度
// P17
#define NTC_GPIO_PORT GPIO_P1
#define NTC_GPIO_BIT 7

#endif /* End of BOARD_H */
