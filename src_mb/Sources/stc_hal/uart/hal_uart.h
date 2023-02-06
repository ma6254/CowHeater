#ifndef HAL_UART_H
#define HAL_UART_H

#include "hal_sys.h"

#define CONFIG_HAL_ENABLE_UART1 1

#define UART_QUEUE_SIZE (32)

typedef struct
{
    uint8_t buf[UART_QUEUE_SIZE];
    uint8_t head;
    uint8_t tail;
} uart_queue_t;

#ifdef CONFIG_HAL_ENABLE_UART1

typedef enum
{
    HAL_UART1_IOMUX_P30_P31, // default
    HAL_UART1_IOMUX_P36_P37,
    HAL_UART1_IOMUX_P16_P17,
    HAL_UART1_IOMUX_P43_P44,
} hal_uart1_iomux_t;

void hal_uart1_init(uint32_t baud, hal_uart1_iomux_t iomux);

uint8_t hal_uart1_write_byte(uint8_t a);
// uint8_t uart_queue_available(uart_queue_t *p_queue);

#define hal_uart1_interrupt_allow() (ES = 1)
#define hal_uart1_interrupt_reject() (ES = 0)

#define hal_uart2_interrupt_allow() (ES2 = 1)
#define hal_uart2_interrupt_reject() (ES2 = 0)

#define hal_uart3_interrupt_reject() (ES3 = 0)
#define hal_uart3_interrupt_allow() (ES3 = 1)

#define hal_uart4_interrupt_reject() (ES4 = 0)
#define hal_uart4_interrupt_allow() (ES4 = 1)

#define hal_uart1_ri_read() (RI)
#define hal_uart1_ri_clear() (RI = 0)
#define hal_uart1_ti_read() (TI)
#define hal_uart1_ti_clear() (TI = 0)

#endif // End of CONFIG_HAL_ENABLE_UART1

#define hal_uart2_ri_read() (S2CON & B0000_0001)
#define hal_uart2_ri_clear() (S2CON &= ~B0000_0001)
#define hal_uart2_ti_read() (S2CON & B0000_0010)
#define hal_uart2_ti_clear() (S2CON &= ~B0000_0010)

#define hal_uart3_ri_read() (S3CON & B0000_0001)
#define hal_uart3_ri_clear() (S3CON &= ~B0000_0001)
#define hal_uart3_ti_read() (S3CON & B0000_0010)
#define hal_uart3_ti_clear() (S3CON &= ~B0000_0010)

#define hal_uart4_ri_read() (S4CON & B0000_0001)
#define hal_uart4_ri_clear() (S4CON &= ~B0000_0001)
#define hal_uart4_ti_read() (S4CON & B0000_0010)
#define hal_uart4_ti_clear() (S4CON &= ~B0000_0010)

#define HAL_UART1_SBUF (SBUF)
#define hal_uart2_sbuf (S2BUF)
#define hal_uart3_sbuf (S3BUF)
#define hal_uart4_sbuf (S4BUF)

#endif // End of HAL_UART_H
