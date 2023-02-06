#include "sensor.h"

#include "hal_timer.h"
#include "hal_adc.h"

#define SENSOR_TASK_TIME ((time_t)10)

sensor_t gSensor;
data uint32_t sensor_task_tmp_time = 0;

struct Slide_Filter heat_temp_filt;

void sensor_task(void)
{
    static int16_t tmp_i16 = 0;

    if (hal_delay_ms(&sensor_task_tmp_time, SENSOR_TASK_TIME))
    {
        gSensor.raw_adc_tc = hal_adc_read(HAL_ADC_CH1);
        gSensor.raw_adc_ntc = hal_adc_read(HAL_ADC_CH7);
        gSensor.raw_adc_inte = hal_adc_read(HAL_ADC_V119);

        // NTC温度换算
        if (gSensor.raw_adc_ntc > 3325)
            tmp_i16 = -100;
        else if (gSensor.raw_adc_ntc < 1508)
            tmp_i16 = 400;
        else
            tmp_i16 = 400 - (gSensor.raw_adc_ntc - 1508) / 3.634;
        gSensor.ntc_temp = tmp_i16;

        // 热电偶温度换算
        tmp_i16 = (int32_t)(gSensor.ntc_temp) +
                  (int32_t)(gSensor.raw_adc_tc) * 100 / 41;
        gSensor.heat_temp = Slide_Filter_Push(&heat_temp_filt, 32, tmp_i16);
    }
}

/*******************************************************************************
 * @brief 滑动滤波
 * @param s 滤波结构体
 * @param Filt_Cnt 滤波次数
 * @param val 输入值
 * @return None
 ******************************************************************************/
uint16_t Slide_Filter_Push(struct Slide_Filter *s, uint8_t Filt_Cnt, uint16_t val)
{
    uint8_t i = 0;
    uint32_t sum = 0;
    uint8_t max_index = 0, min_index = 0;

    s->Array[s->P] = val;
    s->P++;
    s->P %= Filt_Cnt;

    if (s->C < Filt_Cnt)
    {
        s->C++;
        s->Result = val;
        return val;
    }

    // 求平均时滤除最大值和最小值
    for (i = 1; i < Filt_Cnt; i++)
    {
        if (s->Array[i] < s->Array[min_index])
        {
            min_index = i;
        }
        if (s->Array[i] > s->Array[max_index])
        {
            max_index = i;
        }
    }

    for (i = 0; i < Filt_Cnt; i++)
    {
        if ((i == max_index) || (i == min_index))
            continue;
        sum += s->Array[i];
    }

    if (max_index == min_index)
        s->Result = sum / (Filt_Cnt - 1);
    else
        s->Result = sum / (Filt_Cnt - 2);

    return s->Result;
}
