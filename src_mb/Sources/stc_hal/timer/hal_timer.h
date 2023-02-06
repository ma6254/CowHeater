#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include "hal_sys.h"
#include "port_route.h"

extern uint32_t data hal_uptime;

typedef uint32_t time_t;

void hal_timer2_init(uint32_t interval);

BOOL hal_delay_ms(uint32_t data *tmp_time, uint32_t duration);

#endif /* End of HAL_TIMER_H */
