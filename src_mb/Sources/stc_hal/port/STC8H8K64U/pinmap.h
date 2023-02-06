#ifndef PINMAP_H
#define PINMAP_H

#include "model_meta.h"
#include "port/STC8H/pinmap.h"

#if CHIP_FOOTPRINT == CHIP_FOOTPRINT_LQFP64

// analog port
#define AN_NUM 15
#define GPIO_AN0 GPIO_P10  // 4'b0000 P1.0 / ADC0
#define GPIO_AN1 GPIO_P11  // 4'b0001 P1.1 / ADC1
#define GPIO_AN2 GPIO_P54  // 4'b0010 P5.4 / ADC2
#define GPIO_AN3 GPIO_P13  // 4'b0011 P1.3 / ADC3
#define GPIO_AN4 GPIO_P14  // 4'b0100 P1.4 / ADC4
#define GPIO_AN5 GPIO_P15  // 4'b0101 P1.5 / ADC5
#define GPIO_AN6 GPIO_P16  // 4'b0110 P1.6 / ADC6
#define GPIO_AN7 GPIO_P17  // 4'b0111 P1.7 / ADC7
#define GPIO_AN8 GPIO_P00  // 4'b1000 P0.0 / ADC8
#define GPIO_AN9 GPIO_P01  // 4'b1001 P0.1 / ADC9
#define GPIO_AN10 GPIO_P02 // 4'b1010 P10.2/ ADC10
#define GPIO_AN11 GPIO_P03 // 4'b1011 P10.3/ ADC11
#define GPIO_AN12 GPIO_P04 // 4'b1100 P10.4/ ADC12
#define GPIO_AN13 GPIO_P05 // 4'b1101 P10.5/ ADC13
#define GPIO_AN14 GPIO_P06 // 4'b1110 P10.6/ ADC14
// 4'b1111 inte 1.19V

#define AN_P10 0
#define AN_P11 1
#define AN_P54 2
#define AN_P13 3
#define AN_P14 4
#define AN_P15 5
#define AN_P16 6
#define AN_P17 7
#define AN_P00 8
#define AN_P01 9
#define AN_P02 10
#define AN_P03 11
#define AN_P04 12
#define AN_P05 13
#define AN_P06 14
#define AN_INTE119 15

#elif CHIP_FOOTPRINT == CHIP_FOOTPRINT_TSSOP20 /* End of CHIP_FOOTPRINT_LQFT64 */

/*******************************************************************************
 *
 * gpio define
 * 普通IO口定义
 *
 ******************************************************************************/

#define GPIO_NUM 16 // 总计普通IO数量

// left side
// 左侧列
#define GPIO_P14 14 // SDA/MISO/PWM3P/ADC4/P1.4
#define GPIO_P15 15 // SCL/SCLK/PWM3N/ADC5/P1.5
#define GPIO_P16 16 //
#define GPIO_P17 17 //
#define GPIO_P13 13 //
// UCap
#define GPIO_P54 54 // T2/ADC2/PWM6_2/PWM2P/SS_3/SS/MCLKO/NRST/PWM6_2/P5.4
// Vcc/AVcc
// Gnd/AGnd

// right side
// 右侧列
#define GPIO_P10 10 // P1.0/ADC0/RxD2/PWM1P
#define GPIO_P11 11 // P1.1/ADC1/TxD2/PWM1N
#define GPIO_P37 37 // P3.7/INT3/TxD_2/CMP+
#define GPIO_P36 36 // P3.6/INT2/RxD_2/CMP-
#define GPIO_P35 35 // P3.5/T1/T0CLKO/SS_4/PWMFLT/PWMFLT2
#define GPIO_P34 34 // P3.4/T0/T1CLKO/MOSI_4/PWM4P_4/PWM8_2/CMPO
#define GPIO_P33 33 // P3.3/INT1/MISO_4/I2CSDA_4/PWM4N_4/PWM7_2
#define GPIO_P32 32 // P3.2/INT0/SCLK_4/I2CSCL_4/PWMETI/PWMETI2
#define GPIO_P31 31 // P3.1/TxD/D+
#define GPIO_P30 30 // P3.0/RxD/D-/INT4

/*******************************************************************************
 *
 * analog port define
 * 模拟口定义
 *
 ******************************************************************************/

#define AD_NUM 7          // 总计ADC口数量

// analog port
#define GPIO_AD0 GPIO_P10 // 4'b0000 P1.0 / ADC0
#define GPIO_AD1 GPIO_P11 // 4'b0001 P1.1 / ADC1
#define GPIO_AD3 GPIO_P13 // 4'b0011 P1.3 / ADC3
#define GPIO_AD4 GPIO_P14 // 4'b0100 P1.4 / ADC4
#define GPIO_AD5 GPIO_P15 // 4'b0101 P1.5 / ADC5
#define GPIO_AD6 GPIO_P16 // 4'b0110 P1.6 / ADC6
#define GPIO_AD7 GPIO_P17 // 4'b0111 P1.7 / ADC7

// GPIO转ADC通道
#define AN_P10 ADC_CH0
#define AN_P11 ADC_CH1
#define AN_P13 ADC_CH3
#define AN_P14 ADC_CH4
#define AN_P15 ADC_CH5
#define AN_P16 ADC_CH6
#define AN_P17 ADC_CH7

#else /* End of CHIP_FOOTPRINT_TSSOP20 */
#error "Unknown CHIP_FOOTPRINT"
#endif /* End of Unknown CHIP_FOOTPRINT */

#endif /* End of PINMAP_H */
