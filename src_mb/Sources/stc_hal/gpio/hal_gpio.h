#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "hal_sys.h"

typedef void (*gpio_writer_handler)(uint8_t level);
typedef uint8_t (*gpio_reader_handler)(void);

typedef enum
{
    gpio_mode_output,       // 输出
    gpio_mode_output_force, // 推挽输出
    gpio_mode_in,           // 高阻输入
    gpio_mode_od,           // 开漏输出
} gpio_mode_t;

typedef enum
{
    gpio_isr_fall_edge, // 下降沿中断
    gpio_isr_rise_edge, // 上升沿中断
    gpio_isr_low,       // 低电平中断
    gpio_isr_high,      // 高电平中断
} gpio_isr_mode_t;

typedef struct
{
    uint8_t port;
    uint8_t xbit;
    gpio_mode_t mode;

    // 使能端口内部的 4.1K 上拉电阻
    bool_t en_pullup;

    // 使能端口中断
    bool_t en_isr;

    // 中断模式
    gpio_isr_mode_t isr_mode;

} gpio_t;

void hal_gpio_struct_default(gpio_t *p_gpio);
BOOL hal_gpio_config_apply(gpio_t *p_gpio);

/*******************************************************************************
 * GPIO
 ******************************************************************************/
#define GPIO_P0 0
#define GPIO_P1 1
#define GPIO_P2 2
#define GPIO_P3 3
#define GPIO_P4 4
#define GPIO_P5 5
#define GPIO_P6 6
#define GPIO_P7 7

#define GPIO_PORT_NUM 8

void hal_gpio_all_in_pullup(void);

#define Init_IO_Out_L(port, pin) Init_IO_Out_L_Res(port, pin)
#define Init_IO_Out_L_Res(port, pin) (P##port##M0 |= (1 << pin), P##port##M1 &= ~(1 << pin), P##port &= ~(1 << pin))

#define Init_IO_Out_H(port, pin) Init_IO_Out_H_Res(port, pin)
#define Init_IO_Out_H_Res(port, pin) (P##port##M0 |= (1 << pin), P##port##M1 &= ~(1 << pin), P##port |= (1 << pin))

#define Init_IO_In_Up(port, pin) Init_IO_In_Up_Res(port, pin)
#define Init_IO_In_Up_Res(port, pin) (P##port##M0 &= ~(1 << pin), P##port##M1 |= (1 << pin), P##port##PU |= (1 << pin), P##port |= (1 << pin))

#define Init_IO_In_NoUp(port, pin) Init_IO_In_NoUp_Res(port, pin)
#define Init_IO_In_NoUp_Res(port, pin) (P##port##M0 &= ~(1 << pin), P##port##M1 &= ~(1 << pin), P##port##PU &= ~(1 << pin))

#define Init_IO_Out_Keep(port, pin) Init_IO_Out_Keep_Res(port, pin)
#define Init_IO_Out_Keep_Res(port, pin) (P##port##M0 |= (1 << pin), P##port##M1 &= ~(1 << pin))

// #define IO_Out_H_Res(port, pin) (P##port |= (1 << pin))  // 对应PIN拼接
// #define IO_Out_L_Res(port, pin) (P##port &= ~(1 << pin)) // 对应PIN拼接
// #define IO_Read_Res(port, pin) (P##port & (1 << pin))    // 对应PIN拼接
#define IO_Out_H_Res(xPort, xPin) (P##xPort##xPin = 1) // 对应PIN拼接
#define IO_Out_L_Res(xPort, xPin) (P##xPort##xPin = 0) // 对应PIN拼接
#define IO_Read_Res(xPort, xPin) (P##xPort##xPin)      // 对应PIN拼接

#define IO_Out_H(xPort, xPin) IO_Out_H_Res(xPort, xPin) // 对应PIN输出高电平
#define IO_Out_L(xPort, xPin) IO_Out_L_Res(xPort, xPin) // 对应PIN输出低电平
#define IO_Read(xPort, xPin) IO_Read_Res(xPort, xPin)   // 对应PIN数据读取

#define IO_Out_Op(x, port, pin) ((x) ? IO_Out_H(port, pin) : IO_Out_L(port, pin))

#define IO_Out_Flip(port, pin) IO_Read(port, pin) ? IO_Out_L(port, pin) : IO_Out_H(port, pin)

#endif /* End of HAL_GPIO_H */
