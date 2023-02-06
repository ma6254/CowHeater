#ifndef HAL_ADC_H
#define HAL_ADC_H

#include "hal_sys.h"

void hal_adc_init(void);

#define hal_adc_power_on() (ADC_CONTR |= B1000_0000)
#define hal_adc_power_off() (ADC_CONTR &= ~B1000_0000)

#define hal_adc_start() (ADC_CONTR |= B0100_0000)
#define hal_adc_done() ((ADC_CONTR & B0100_0000) == 0)

typedef enum
{
    HAL_ADC_CH0 = 0,
    HAL_ADC_CH1,
    HAL_ADC_CH2,
    HAL_ADC_CH3,
    HAL_ADC_CH4,
    HAL_ADC_CH5,
    HAL_ADC_CH6,
    HAL_ADC_CH7,
    HAL_ADC_CH8,
    HAL_ADC_CH9,
    HAL_ADC_CH10,
    HAL_ADC_CH11,
    HAL_ADC_CH12,
    HAL_ADC_CH13,
    HAL_ADC_CH14,
    HAL_ADC_CH15,
} hal_adc_chan_t;

#define HAL_ADC_V119 (HAL_ADC_CH15)

uint16_t hal_adc_read(hal_adc_chan_t ch);

#define hal_adc_chan_sel(x_chan)            \
    {                                       \
        ADC_CONTR &= ~B0000_1111;           \
        ADC_CONTR |= (x_chan & B0000_1111); \
    }

#define hal_adc_result_align_left() (ADCCFG &= ~B0010_0000)
#define hal_adc_result_align_right() (ADCCFG |= B0010_0000)

enum
{
    HAL_ADC_CLK_DIV_2 = 0, // 0000
    HAL_ADC_CLK_DIV_4,     // 0001
    HAL_ADC_CLK_DIV_6,     // 0010
    HAL_ADC_CLK_DIV_8,     // 0011
    HAL_ADC_CLK_DIV_10,    // 0100
    HAL_ADC_CLK_DIV_12,    // 0101
    HAL_ADC_CLK_DIV_14,    // 0110
    HAL_ADC_CLK_DIV_16,    // 0111
    HAL_ADC_CLK_DIV_18,    // 1000
    HAL_ADC_CLK_DIV_20,    // 1001
    HAL_ADC_CLK_DIV_22,    // 1010
    HAL_ADC_CLK_DIV_24,    // 1011
    HAL_ADC_CLK_DIV_26,    // 1100
    HAL_ADC_CLK_DIV_28,    // 1101
    HAL_ADC_CLK_DIV_30,    // 1110
    HAL_ADC_CLK_DIV_32,    // 1111
};

#define hal_adc_resule_read() ((uint16_t)((uint8_t)ADC_RES) << 8 | (uint16_t)((uint8_t)ADC_RESL) << 0)

#endif // End of HAL_ADC_H
