#ifndef PORT_ROUTE_H
#define PORT_ROUTE_H

#include "model_meta.h"

#ifndef CHIP_FOOTPRINT
#error "Not Define CHIP_MODEL"
#endif

#ifndef CHIP_FOOTPRINT
#error "Not Define CHIP_FOOTPRINT"
#endif

#if CHIP_MODEL == CHIP_MODEL_STC8H8K64U
#include "port/STC8H8K64U/pinmap.h"
#else
#error "Unknown CHIP_MODEL"
#endif

#define _Get_Pin_ADChan_(xPort, xPIN) AN_P##xPIN##xPort
#define Get_Pin_ADChan(xPort, xPIN) _Get_Pin_ADChan_(xPort, xPIN)

#endif /* End of PORT_ROUTE_H */
