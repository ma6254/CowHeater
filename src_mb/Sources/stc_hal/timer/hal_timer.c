#include "hal_timer.h"

uint32_t data hal_uptime = 0;

/*******************************************************************************
 * @brief 初始化定时器2
 * @param t 定时器号2
 * @param interval 时间间隔，单位uS
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
 * @brief 定时器毫秒延时
 * @param tmp_time 缓存时间戳
 * @param duration 时间间隔，单位ms
 * @return bool 0: 时间未到; 1: 时间已到
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
