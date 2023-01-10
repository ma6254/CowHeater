#ifndef _H_HAL_MODEL_
#define _H_HAL_MODEL_

#include "../config/hal_config.h"
#include "std/pinmap.h"
#include "std/model_meta.h"

#if CHIP_MODEL == CHIP_MODEL_STC8H_GENERIC
/*******************************************************************************
 * CHIP_MODEL_STC8H_GENERIC
 ******************************************************************************/
#include "model\STC8H\include\hal_core.h"
#include "model\STC8H\include\hal_gpio.h"

#elif CHIP_MODEL == CHIP_MODEL_STC8H8K64U
/*******************************************************************************
 * CHIP_MODEL_STC8H8K64U
 ******************************************************************************/
#include "model\STC8H8K64U\include\hal_core.h"
#include "model\STC8H\include\hal_gpio.h"

#else
/*******************************************************************************
 * Unknow Chip Model
 ******************************************************************************/
#error "Unknow CHIP_MODEL"
#endif

#endif
