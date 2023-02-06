#include "load.h"
#include "sensor.h"
#include "board.h"

#include "hal_timer.h"
#include "hal_adc.h"

#define LOAD_TASK_TIME ((time_t)1000)

data load_t G_LOAD;
data time_t load_task_tmp_time = 0;

float last_delta = 0;
int16_t pid_p_calc(int16_t target, int16_t feedback)
{
    float delta = 0;
    float delta2 = 0;
    delta = (float)target - feedback;
    delta2 = delta - last_delta;
    last_delta = delta;

    return (int16_t)((delta2 * 3.673) + (delta * 0.138));
}

/*******************************************************************************
 * @brief 实现回调函数(gpio_writer_handler)，输出晶闸管门控脚信号
 * @param level 电平
 * @return None
 ******************************************************************************/
void load_triac_pin_writer(uint8_t level)
{
    if (level != 0)
        IO_Out_H(HEAT_GPIO_PORT, HEAT_GPIO_BIT);
    else
        IO_Out_L(HEAT_GPIO_PORT, HEAT_GPIO_BIT);
}

/*******************************************************************************
 * @brief 初始化负载结构体
 * @param l 负载结构体实例指针
 * @return None
 ******************************************************************************/
void load_init(load_t *pLoad)
{
    triac_init(&pLoad->triac, load_triac_pin_writer);
}

void load_task(void)
{
    if (hal_delay_ms(&load_task_tmp_time, LOAD_TASK_TIME))
    {

        G_LOAD.power_scale += pid_p_calc(G_LOAD.target_temp, gSensor.heat_temp);
        if (G_LOAD.power_scale > 1000)
            G_LOAD.power_scale = 1000;
        else if (G_LOAD.power_scale < 0)
            G_LOAD.power_scale = 0;
        G_LOAD.triac.duty = (G_LOAD.power_scale + 50) / 100;
    }
}
