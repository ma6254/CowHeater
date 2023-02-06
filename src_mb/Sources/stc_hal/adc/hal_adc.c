#include "hal_adc.h"

void hal_adc_init(void)
{
    hal_adc_power_on();
    ADCTIM = 0x3F;
    ADCEXCFG = 0x00;
    ADCCFG = 0x0F;
    hal_adc_result_align_right();
}

uint16_t hal_adc_read(hal_adc_chan_t ch)
{
    hal_adc_chan_sel(ch);
    hal_adc_start();
    while (hal_adc_done() == FALSE)
        ;
    return hal_adc_resule_read();
}
