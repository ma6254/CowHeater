#include <stdio.h>
#include <STC8H.h>

#include "stc_hal_config.h"
#include "hal_sys.h"
#include "board.h"
#include "hal_gpio.h"
#include "hal_timer.h"
#include "hal_adc.h"
#include "hal_uart.h"
#include "hal_config_msg.h"

#include "load.h"
#include "sensor.h"

/*******************************************************************************
 * @brief GPIO初始化
 * @param None
 * @return None
 ******************************************************************************/
void sys_gpio_init(void)
{
    // gpio_t tmp_gpio;

    // hal_gpio_struct_default(&tmp_gpio);
    // tmp_gpio.port = LED_GPIO_PORT;
    // tmp_gpio.xbit = LED_GPIO_BIT;
    // tmp_gpio.mode = gpio_mode_output;
    // hal_gpio_config_apply(&tmp_gpio);

    // hal_gpio_struct_default(&tmp_gpio);
    // tmp_gpio.port = HEAT_GPIO_PORT;
    // tmp_gpio.xbit = HEAT_GPIO_BIT;
    // tmp_gpio.mode = gpio_mode_output;
    // hal_gpio_config_apply(&tmp_gpio);

    Init_IO_Out_L(LED_GPIO_PORT, LED_GPIO_BIT);
    Init_IO_Out_L(HEAT_GPIO_PORT, HEAT_GPIO_BIT);

    Init_IO_Out_H(3, 1);
    Init_IO_In_Up(3, 0);

    Init_IO_In_NoUp(TEMP_GPIO_PORT, TEMP_GPIO_BIT);
    IO_Out_H(TEMP_GPIO_PORT, TEMP_GPIO_BIT);
    P1IE &= ~B0000_0010;

    Init_IO_In_NoUp(NTC_GPIO_PORT, NTC_GPIO_BIT);
    IO_Out_H(NTC_GPIO_PORT, NTC_GPIO_BIT);
    P1IE &= ~B1000_0000;
}

/*******************************************************************************
 * @brief 初始化
 * @param None
 * @return None
 ******************************************************************************/
void sys_init(void)
{
    /***************************************************************************
     * 外设初始化
     **************************************************************************/
    En_XFR();
    sys_gpio_init();
    hal_timer2_init(1000);
    // UartInit();
    hal_uart1_init(115200, HAL_UART1_IOMUX_P30_P31);
    hal_adc_init();

    /***************************************************************************
     * 组件初始化
     **************************************************************************/
    gload_init();

    /***************************************************************************
     * 上电初始化流程
     **************************************************************************/
    hal_allow_all_interrupt();
    // Delay_PowerUp();
}

#define TARGET_TEMP ((int16_t)800)

data uint32_t hello_led_tmp_time = 0;

BOOL zn_old_status;
data uint32_t zn_last_time = 0;
data uint32_t zn_time = 0;
int16_t zn_max_tmp_temp = 0;
int16_t zn_min_tmp_temp = 0;
int16_t zn_max_temp = 0;
int16_t zn_min_temp = 0x7FFF;

/*******************************************************************************
 * @brief 主函数，程序入口
 * @param None
 * @return None
 ******************************************************************************/
void main(void)
{
    hal_init();
    sys_init();
    while (1)
    {

        if (hal_delay_ms(&hello_led_tmp_time, 250))
        {
            IO_Out_Flip(1, 3);
        }

        // if (hal_delay_ms(&aaa_tmp_time, 1000))
        // {
        //     if (G_LOAD.triac.duty)
        //         G_LOAD.triac.duty = 0;
        //     else
        //         G_LOAD.triac.duty = 10;

        //     if (heat_temp_filt.Result > TARGET_TEMP)
        //     {
        //         G_LOAD.triac.duty = 0;

        //         if (zn_old_status == TRUE)
        //         {
        //             zn_time = hal_uptime - zn_last_time;
        //             zn_last_time = hal_uptime;

        //             zn_max_temp = zn_max_tmp_temp;
        //             zn_min_temp = zn_min_tmp_temp;
        //             zn_max_tmp_temp = 0;
        //             zn_min_tmp_temp = 0x7FFF;
        //         }
        //         zn_old_status = FALSE;
        //     }
        //     else
        //     {
        //         G_LOAD.triac.duty = 10;
        //         zn_old_status = TRUE;
        //     }
        // }

        sensor_task();
        load_task();
        debug_print_task();
    }
}
