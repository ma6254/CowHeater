#ifndef _H_HAL_PINMAP_
#define _H_HAL_PINMAP_

#define _Get_Pin_GPIO_Group_(xPIN) PIN_##xPIN##_PORT_GROUP
#define Get_Pin_GPIO_Group(xPIN) _Get_Pin_GPIO_Group_(xPIN)

#define _Get_Pin_GPIO_Bit_(xPIN) PIN_##xPIN##_PORT_BIT
#define Get_Pin_GPIO_Bit(xPIN) _Get_Pin_GPIO_Bit_(xPIN)

#endif
