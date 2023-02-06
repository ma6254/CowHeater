#ifndef BASE_PINMAP_H
#define BASE_PINMAP_H

/*******************************************************************************
 *
 * ADC define
 *
 ******************************************************************************/

#define ADC_CH0 0
#define ADC_CH1 1
#define ADC_CH2 2
#define ADC_CH3 3
#define ADC_CH4 4
#define ADC_CH5 5
#define ADC_CH6 6
#define ADC_CH7 7
#define ADC_CH8 8
#define ADC_CH9 9
#define ADC_CH10 10
#define ADC_CH11 11
#define ADC_CH12 12
#define ADC_CH13 13
#define ADC_CH14 14
#define ADC_CH15 15

#define ADC_119 ADC_CH15 // ≤‚ ‘ƒ⁄≤ø 1.19V

/*******************************************************************************
 *
 * Timer
 *
 ******************************************************************************/
typedef enum
{
    TIMER_0,
    TIMER_1,
    TIMER_2,
    TIMER_3,
    TIMER_4,
} timer_t;

#endif
