#ifndef BOARD_H
#define BOARD_H

#include "hal_sys.h"

// ������LED
// P13
#define LED_GPIO_PORT 1
#define LED_GPIO_BIT 3

// �ɿع�������
// P10
#define HEAT_GPIO_PORT GPIO_P1
#define HEAT_GPIO_BIT 0

// ���Ȱ��¶ȣ��ȵ�ż�źŲ���
// P11
#define TEMP_GPIO_PORT GPIO_P1
#define TEMP_GPIO_BIT 1

// ����¶�
// P17
#define NTC_GPIO_PORT GPIO_P1
#define NTC_GPIO_BIT 7

#endif /* End of BOARD_H */
