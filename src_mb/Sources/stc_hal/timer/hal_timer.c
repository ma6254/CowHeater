#include "hal_timer.h"

uint32_t data hal_uptime = 0;

/*******************************************************************************
 * @brief ��ʼ����ʱ��2
 * @param t ��ʱ����2
 * @param interval ʱ��������λuS
 * @return None
 ******************************************************************************/
void hal_timer2_init(uint32_t interval)
{
    uint16_t timer_count_set = 0;
    timer_count_set = ((uint32_t)65536) - g_hal_sys_clk_freq / interval;

    Clr8Bit(AUXR, 4);
    Clr8Bit(AUXR, 3);
    Set8Bit(AUXR, 2);
    T2H = ((uint8_t)(timer_count_set >> 8));
    T2L = ((uint8_t)timer_count_set);
    Set8Bit(IE2, 2);
    Set8Bit(AUXR, 4);
}

/*******************************************************************************
 * @brief ��ʱ��������ʱ
 * @param tmp_time ����ʱ���
 * @param duration ʱ��������λms
 * @return bool 0: ʱ��δ��; 1: ʱ���ѵ�
 ******************************************************************************/
BOOL hal_delay_ms(uint32_t data *tmp_time, uint32_t duration)
{
    if (hal_uptime >= (*tmp_time + duration))
    {
        *tmp_time = hal_uptime;
        return TRUE;
    }

    return FALSE;
}
