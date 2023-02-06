#include <string.h>
#include "hal_uart.h"
#include "hal_gpio.h"
#include "hal_timer.h"

// uint8_t uart_queue_available(uart_queue_t *p_queue)
// {
//     uint8_t rxBufLength = 0;
//     rxBufLength = ((uint8_t)(UART_QUEUE_SIZE + p_queue->head - p_queue->tail)) % UART_QUEUE_SIZE;
//     return rxBufLength;
// }

#ifdef CONFIG_HAL_ENABLE_UART1
uart_queue_t hal_uart1_tx_queue;
data BOOL hal_uart1_flag_sending = FALSE;

/*******************************************************************************
 * @brief ��ʼ������1
 * @param baud ������
 * @param iomux ���ö˿�
 * @return None
 ******************************************************************************/
void hal_uart1_init(uint32_t baud, hal_uart1_iomux_t iomux)
{
    uint32_t tmp_u32 = 0;

    tmp_u32 = CHIP_FREQ / baud / 4;
    tmp_u32 = 0x10000 - tmp_u32;

    memset(&hal_uart1_tx_queue, 0, sizeof(hal_uart1_tx_queue));

    switch (iomux)
    {
    case HAL_UART1_IOMUX_P30_P31:
        Init_IO_In_NoUp(3, 0);
        Init_IO_Out_H(3, 1);
        P_SW1 &= ~B1100_0000;
        // P_SW1 |= B0000_0000;
        break;
    // case HAL_UART1_IOMUX_P36_P37:
    //     Init_IO_In_NoUp(3, 6);
    //     Init_IO_Out_H(3, 7);
    //     P_SW1 &= ~B1100_0000;
    //     P_SW1 |= B0100_0000;
    //     break;
    // case HAL_UART1_IOMUX_P16_P17:
    //     Init_IO_In_NoUp(1, 6);
    //     Init_IO_Out_H(1, 7);
    //     P_SW1 &= ~B1100_0000;
    //     P_SW1 |= B1000_0000;
    //     break;
    // case HAL_UART1_IOMUX_P43_P44:
    //     Init_IO_In_NoUp(4, 3);
    //     Init_IO_Out_H(4, 4);
    //     P_SW1 &= ~B1100_0000;
    //     P_SW1 |= B1100_0000;
    //     break;
    default:
        return;
    }

    SCON = 0x50;                   // 8λ����,�ɱ䲨����
    AUXR |= 0x40;                  // ��ʱ��ʱ��1Tģʽ
    AUXR &= 0xFE;                  // ����1ѡ��ʱ��1Ϊ�����ʷ�����
    TMOD &= 0x0F;                  // ���ö�ʱ��ģʽ
    TL1 = (uint8_t)(tmp_u32);      // ���ö�ʱ��ʼֵ
    TH1 = (uint8_t)(tmp_u32 >> 8); // ���ö�ʱ��ʼֵ
    ET1 = 0;                       // ��ֹ��ʱ���ж�
    TR1 = 1;                       // ��ʱ��1��ʼ��ʱ
    TI = 1;
}

/*******************************************************************************
 * @brief ������1�Ķ���������1�ֽ�����
 * @param a ����
 * @return None
 ******************************************************************************/
uint8_t hal_uart1_write_byte(uint8_t a)
{
    uint8_t nextHeadPos = 0;
    data uint32_t delay_tmp = 0;

    hal_uart1_interrupt_reject();

    if ((hal_uart1_tx_queue.head == hal_uart1_tx_queue.tail) &&
        (hal_uart1_flag_sending == FALSE))
    {
        hal_uart1_flag_sending = TRUE;
        HAL_UART1_SBUF = a;
        hal_uart1_interrupt_allow();
        return 1;
    }

    nextHeadPos = (hal_uart1_tx_queue.head + 1) % UART_QUEUE_SIZE;

    while (nextHeadPos == hal_uart1_tx_queue.tail)
    {
        hal_uart1_interrupt_allow();
        while (hal_delay_ms(&delay_tmp, 1))
            ;
        hal_uart1_interrupt_reject();
    }
    hal_uart1_tx_queue.buf[hal_uart1_tx_queue.head] = a;
    hal_uart1_tx_queue.head = nextHeadPos;

    hal_uart1_interrupt_allow();
    return 1;
}

/*******************************************************************************
 * @brief �жϺ���������1
 * @param None
 * @return None
 ******************************************************************************/
void hal_interrupt_handler_uart1()
#ifdef __KEIL_C51__
    interrupt 4
#endif // End of __KEIL_C51__
{
    if (hal_uart1_ri_read())
    {
        hal_uart1_ri_clear();
    }

    if (hal_uart1_ti_read())
    {
        hal_uart1_ti_clear();
        if (hal_uart1_flag_sending == TRUE)
        {
            if (hal_uart1_tx_queue.head == hal_uart1_tx_queue.tail)
            {
                hal_uart1_flag_sending = FALSE;
            }
            else
            {
                HAL_UART1_SBUF = hal_uart1_tx_queue.buf[hal_uart1_tx_queue.tail];
                hal_uart1_tx_queue.tail = (hal_uart1_tx_queue.tail + 1) % UART_QUEUE_SIZE;
            }
        }
    }
}
#endif // End of CONFIG_HAL_ENABLE_UART1

#ifdef CONFIG_HAL_ENABLE_UART2
BOOL hal_uart2_flag_sending = 0;

/*******************************************************************************
 * @brief �жϺ���������2
 * @param None
 * @return None
 ******************************************************************************/
void hal_interrupt_handler_uart2()
#ifdef __KEIL_C51__
    interrupt 8
#endif // End of __KEIL_C51__
{
    if (hal_uart2_ri_read())
    {
        hal_uart2_ri_clear();
    }

    if (hal_uart2_ti_read())
    {
        hal_uart2_ti_clear();
    }
}
#endif // End of CONFIG_HAL_ENABLE_UART2

#ifdef CONFIG_HAL_ENABLE_UART3
BOOL hal_uart3_flag_sending = 0;

/*******************************************************************************
 * @brief �жϺ���������3
 * @param None
 * @return None
 ******************************************************************************/
void hal_interrupt_handler_uart3() interrupt 17
{
    if (hal_uart3_ri_read())
    {
        hal_uart3_ri_clear();
    }

    if (hal_uart3_ti_read())
    {
        hal_uart3_ti_clear();
    }
}
#endif // End of CONFIG_HAL_ENABLE_UART3

#ifdef CONFIG_HAL_ENABLE_UART4
BOOL hal_uart4_flag_sending = 0;

/*******************************************************************************
 * @brief �жϺ���������4
 * @param None
 * @return None
 ******************************************************************************/
void hal_interrupt_handler_uart4() interrupt 18
{
    if (hal_uart4_ri_read())
    {
        hal_uart4_ri_clear();
    }

    if (hal_uart4_ti_read())
    {
        hal_uart4_ti_clear();
    }
}
#endif // End of CONFIG_HAL_ENABLE_UART4
