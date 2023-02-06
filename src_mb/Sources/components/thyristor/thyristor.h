/*******************************************************************************
 * ¾§Õ¢¹Ü¿ØÖÆ
 ******************************************************************************/
#ifndef THYRISTOR_H
#define THYRISTOR_H

#include "hal_sys.h"
#include "hal_gpio.h"

typedef enum
{
    TRIAC_LEVEL_0 = 0, // off
    triac_level_1,
    triac_level_2,
    triac_level_3,
    triac_level_4,
    triac_level_5,
    triac_level_6,
    triac_level_7,
    triac_level_8,
    triac_level_9,
    triac_level_10, // full power
} triac_level_t;

#define TRIAC_LEVEL_FULL triac_level_10

typedef struct
{
    gpio_writer_handler gate_pin_writer;
    uint8_t duty;
    uint8_t cycle;
} triac_t;

#define triac_write_pin(pTriac, xLevel) (((pTriac)->gate_pin_writer)((xLevel)))
#define triac_on(pTriac) (triac_write_pin((pTriac), TRUE))
#define triac_off(pTriac) (triac_write_pin((pTriac), FALSE))

extern void triac_init(triac_t *t, gpio_writer_handler fn);
// extern void triac_set_duty(triac_t *t, triac_level_t level);
// void triac_duty_inc(triac_t *t, int8_t level);
extern void triac_timer_handler(triac_t *t);
// void triac_exint_handler(triac_t *t);

#endif /* End of THYRISTOR_H */
