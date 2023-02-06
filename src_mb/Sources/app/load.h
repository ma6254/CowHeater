#ifndef LOAD_H
#define LOAD_H

#include "hal_sys.h"
#include "thyristor.h"

typedef struct
{
    triac_t triac;
    int16_t target_temp;

    uint16_t power_scale;
} load_t;

extern data load_t G_LOAD;

void load_init(load_t *l);

#define gload_init() (load_init(&G_LOAD))

void load_task(void);

#endif /* End of LOAD_H */
