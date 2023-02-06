#ifndef HAL_SYS_H
#define HAL_SYS_H

#include <STC8H.h>
#include "bytes.h"
#include "mbits.h"
#include "stc_hal_config.h"

/*******************************************************************************
 * ϵͳ��ʼ��
 ******************************************************************************/

#define En_XFR() (Set8Bit(P_SW2, 7))
#define Dis_XFR() (Clr8Bit(P_SW2, 7))

#define WDT_Init()              \
    {                           \
        WDT_CONTR = B0011_0100; \
    }

#define Clr_WDT() (Set8Bit(WDT_CONTR, 4))

void hal_init(void);

// �ж��ܿ��أ����������ж�
#define hal_deny_all_interrupt() (EA = 0)

// �ж��ܿ��أ����������ж�
#define hal_allow_all_interrupt() (EA = 1)

extern const uint32_t g_hal_sys_clk_freq;

#endif /* End of HAL_SYS_H */
