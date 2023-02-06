#include "hal_sys.h"
#include "hal_gpio.h"
#include "stc_hal_config.h"

/*******************************************************************************
 * @brief HAL框架初始化
 * @param None
 * @return None
 ******************************************************************************/
void Delay_PowerUp(void)
{
    uint16_t delay_i = 6000;
    while (delay_i--)
    {
        // ClrWDT(WDT_1024MS);
    }
}

const uint32_t g_hal_sys_clk_freq = CHIP_FREQ;

/*******************************************************************************
 * @brief HAL框架初始化
 * @param None
 * @return None
 ******************************************************************************/
void hal_init(void)
{
    EA = 0;
    Delay_PowerUp();
    En_XFR();
    CLKSEL = 0x00;
    CLKDIV = 0x00;
    HIRCCR = B1000_0000;
    MCLKOCR = 0x00;
    Delay_PowerUp();

    hal_gpio_all_in_pullup();
}
