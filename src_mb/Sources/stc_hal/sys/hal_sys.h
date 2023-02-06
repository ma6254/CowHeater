#ifndef HAL_SYS_H
#define HAL_SYS_H

#include <STC8H.h>
#include "bytes.h"
#include "mbits.h"
#include "stc_hal_config.h"

/*******************************************************************************
 * 系统初始化
 ******************************************************************************/

#define En_XFR() (Set8Bit(P_SW2, 7))
#define Dis_XFR() (Clr8Bit(P_SW2, 7))

#define WDT_Init()              \
    {                           \
        WDT_CONTR = B0011_0100; \
    }

#define Clr_WDT() (Set8Bit(WDT_CONTR, 4))

void hal_init(void);

// 中断总开关，禁用所有中断
#define hal_deny_all_interrupt() (EA = 0)

// 中断总开关，允许所有中断
#define hal_allow_all_interrupt() (EA = 1)

extern const uint32_t g_hal_sys_clk_freq;

#endif /* End of HAL_SYS_H */
