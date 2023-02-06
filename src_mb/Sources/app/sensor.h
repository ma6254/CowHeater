#ifndef SENSOR_H
#define SENSOR_H

#include "hal_sys.h"

/*******************************************************************************
 * Class Slide_Filter
 ******************************************************************************/
#define Slide_Filter_Len_Max 32
struct Slide_Filter
{
    uint16_t Array[Slide_Filter_Len_Max]; //
    uint8_t P;                            // 当前游标
    uint8_t C;                            //
    uint16_t Result;                      // 滤波结果
};
extern uint16_t Slide_Filter_Push(struct Slide_Filter *s, uint8_t Filt_Cnt, uint16_t val);

typedef struct
{
    uint16_t raw_adc_ntc;
    uint16_t raw_adc_tc;
    uint16_t raw_adc_inte;

    struct Slide_Filter heat_temp_filt;

    int16_t ntc_temp;
    int16_t heat_temp;
} sensor_t;

extern sensor_t gSensor;

void sensor_task(void);

#endif // End of SENSOR_H
