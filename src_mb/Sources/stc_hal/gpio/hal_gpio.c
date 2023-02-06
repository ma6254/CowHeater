#include "hal_gpio.h"

/*******************************************************************************
 * @brief 将所有GPIO设置为输入带上拉
 * @param None
 * @return None
 ******************************************************************************/
void hal_gpio_all_in_pullup(void)
{
    P1 = 0xFF, P1M0 = 0x00, P1M1 = 0xFF;
    P2 = 0xFF, P2M0 = 0x00, P2M1 = 0xFF;
    P3 = 0xFF, P3M0 = 0x00, P3M1 = 0xFF;
    P4 = 0xFF, P4M0 = 0x00, P4M1 = 0xFF;
    P5 = 0xFF, P5M0 = 0x00, P5M1 = 0xFF;
    P6 = 0xFF, P6M0 = 0x00, P6M1 = 0xFF;
    P7 = 0xFF, P7M0 = 0x00, P7M1 = 0xFF;
}

void hal_gpio_struct_default(gpio_t *p_gpio)
{
    p_gpio->port = 0;
    p_gpio->xbit = 0;
    p_gpio->mode = gpio_mode_in;
    p_gpio->en_pullup = 0;
    p_gpio->en_isr = 0;
    p_gpio->isr_mode = gpio_isr_fall_edge;
}

/*******************************************************************************
 * @brief 应用GPIO配置
 * @param p_gpio gpio结构体
 * @return 0:OK, other:Fail
 ******************************************************************************/
BOOL hal_gpio_config_apply(gpio_t *p_gpio)
{
    uint8_t tmp_reg_m0 = 0;
    uint8_t tmp_reg_m1 = 0;
    uint8_t tmp_reg_en_pu = 0;
    uint8_t tmp_reg_en_isr = 0;
    uint8_t tmp_reg_im0 = 0;
    uint8_t tmp_reg_im1 = 0;

    if (p_gpio->port > 7)
        return TRUE;

    if (p_gpio->xbit > 7)
        return TRUE;

    switch (p_gpio->mode)
    {
    case gpio_mode_output:
        tmp_reg_m1 = 0;
        tmp_reg_m0 = 0;
        break;
    case gpio_mode_output_force:
        tmp_reg_m1 = 0;
        tmp_reg_m0 = 1;
        break;
    case gpio_mode_in:
        tmp_reg_m1 = 1;
        tmp_reg_m1 = 1;
        tmp_reg_m0 = 0;
        tmp_reg_m0 = 0;
        break;
    case gpio_mode_od:
        tmp_reg_m1 = 1;
        tmp_reg_m0 = 1;
        break;
    default:
        return TRUE;
    }

    if (p_gpio->en_pullup)
        tmp_reg_en_pu = 1;

    if (p_gpio->en_isr)
        tmp_reg_en_isr = 1;

    switch (p_gpio->isr_mode)
    {
    case gpio_isr_fall_edge:
        tmp_reg_im1 = 0;
        tmp_reg_im0 = 0;
        break;
    case gpio_isr_rise_edge:
        tmp_reg_im1 = 0;
        tmp_reg_im0 = 1;
        break;
    case gpio_isr_low:
        tmp_reg_im1 = 1;
        tmp_reg_im0 = 0;
        break;
    case gpio_isr_high:
        tmp_reg_im1 = 1;
        tmp_reg_im0 = 1;
        break;
    }

    tmp_reg_m0 <<= (p_gpio->xbit);
    tmp_reg_m1 <<= (p_gpio->xbit);
    tmp_reg_en_pu <<= (p_gpio->xbit);
    tmp_reg_en_isr <<= (p_gpio->xbit);
    tmp_reg_im1 <<= (p_gpio->xbit);
    tmp_reg_im0 <<= (p_gpio->xbit);

    switch (p_gpio->port)
    {
    case 0:
        P0M0 = tmp_reg_m0;
        P0M1 = tmp_reg_m1;
        P0PU = tmp_reg_en_pu;
        P0INTE = tmp_reg_en_isr;
        P0IM1 = tmp_reg_im1;
        P0IM0 = tmp_reg_im0;
        break;
    case 1:
        P1M1 = tmp_reg_m1;
        P1M0 = tmp_reg_m0;
        P1PU = tmp_reg_en_pu;
        P1INTE = tmp_reg_en_isr;
        P1IM1 = tmp_reg_im1;
        P1IM0 = tmp_reg_im0;
        break;
    case 2:
        P2M1 = tmp_reg_m1;
        P2M0 = tmp_reg_m0;
        P2PU = tmp_reg_en_pu;
        P2INTE = tmp_reg_en_isr;
        P2IM1 = tmp_reg_im1;
        P2IM0 = tmp_reg_im0;
        break;
    case 3:
        P3M1 = tmp_reg_m1;
        P3M0 = tmp_reg_m0;
        P3PU = tmp_reg_en_pu;
        P3INTE = tmp_reg_en_isr;
        P3IM1 = tmp_reg_im1;
        P3IM0 = tmp_reg_im0;
        break;
    case 4:
        P4M1 = tmp_reg_m1;
        P4M0 = tmp_reg_m0;
        P4PU = tmp_reg_en_pu;
        P4INTE = tmp_reg_en_isr;
        P4IM1 = tmp_reg_im1;
        P4IM0 = tmp_reg_im0;
        break;
    case 5:
        P5M1 = tmp_reg_m1;
        P5M0 = tmp_reg_m0;
        P5PU = tmp_reg_en_pu;
        P5INTE = tmp_reg_en_isr;
        P5IM1 = tmp_reg_im1;
        P5IM0 = tmp_reg_im0;
        break;
    case 6:
        P6M1 = tmp_reg_m1;
        P6M0 = tmp_reg_m0;
        P6PU = tmp_reg_en_pu;
        P6INTE = tmp_reg_en_isr;
        P6IM1 = tmp_reg_im1;
        P6IM0 = tmp_reg_im0;
        break;
    case 7:
        P7M1 = tmp_reg_m1;
        P7M0 = tmp_reg_m0;
        P7PU = tmp_reg_en_pu;
        P7INTE = tmp_reg_en_isr;
        P7IM1 = tmp_reg_im1;
        P7IM0 = tmp_reg_im0;
        break;
    default:
        return TRUE;
    }

    return FALSE;
}
