#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "hal_sys.h"

typedef void (*gpio_writer_handler)(uint8_t level);
typedef uint8_t (*gpio_reader_handler)(void);

typedef enum
{
    gpio_mode_output,       // ���
    gpio_mode_output_force, // �������
    gpio_mode_in,           // ��������
    gpio_mode_od,           // ��©���
} gpio_mode_t;

typedef enum
{
    gpio_isr_fall_edge, // �½����ж�
    gpio_isr_rise_edge, // �������ж�
    gpio_isr_low,       // �͵�ƽ�ж�
    gpio_isr_high,      // �ߵ�ƽ�ж�
} gpio_isr_mode_t;

typedef struct
{
    uint8_t port;
    uint8_t xbit;
    gpio_mode_t mode;

    // ʹ�ܶ˿��ڲ��� 4.1K ��������
    bool_t en_pullup;

    // ʹ�ܶ˿��ж�
    bool_t en_isr;

    // �ж�ģʽ
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

// #define IO_Out_H_Res(port, pin) (P##port |= (1 << pin))  // ��ӦPINƴ��
// #define IO_Out_L_Res(port, pin) (P##port &= ~(1 << pin)) // ��ӦPINƴ��
// #define IO_Read_Res(port, pin) (P##port & (1 << pin))    // ��ӦPINƴ��
#define IO_Out_H_Res(xPort, xPin) (P##xPort##xPin = 1) // ��ӦPINƴ��
#define IO_Out_L_Res(xPort, xPin) (P##xPort##xPin = 0) // ��ӦPINƴ��
#define IO_Read_Res(xPort, xPin) (P##xPort##xPin)      // ��ӦPINƴ��

#define IO_Out_H(xPort, xPin) IO_Out_H_Res(xPort, xPin) // ��ӦPIN����ߵ�ƽ
#define IO_Out_L(xPort, xPin) IO_Out_L_Res(xPort, xPin) // ��ӦPIN����͵�ƽ
#define IO_Read(xPort, xPin) IO_Read_Res(xPort, xPin)   // ��ӦPIN���ݶ�ȡ

#define IO_Out_Op(x, port, pin) ((x) ? IO_Out_H(port, pin) : IO_Out_L(port, pin))

#define IO_Out_Flip(port, pin) IO_Read(port, pin) ? IO_Out_L(port, pin) : IO_Out_H(port, pin)

#endif /* End of HAL_GPIO_H */
