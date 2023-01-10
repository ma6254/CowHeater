#ifndef _H_HAL_MODEL_META_
#define _H_HAL_MODEL_META_

/*******************************************************************************
 * ENUM CHIP_FOOTPRINT
 ******************************************************************************/

// SOP
#define CHIP_FOOTPRINT_SOP8 0x00
#define CHIP_FOOTPRINT_SOP16 0x01
#define CHIP_FOOTPRINT_SOP20 0x02
#define CHIP_FOOTPRINT_SOP24 0x03
#define CHIP_FOOTPRINT_SOP28 0x04

// LQFP
#define CHIP_FOOTPRINT_LQFP32 0x10
#define CHIP_FOOTPRINT_LQFP44 0x11
#define CHIP_FOOTPRINT_LQFP48 0x12
#define CHIP_FOOTPRINT_LQFP64 0x13

// QFN
#define CHIP_FOOTPRINT_QFN20 0x20

/*******************************************************************************
 * ENUM CHIP_MODEL
 ******************************************************************************/

// Sinowealth 00xx
#define CHIP_MODEL_SH79F9261 0x0000
#define CHIP_MODEL_SH79F9476 0x0001

// BYD 01xx
#define CHIP_MODEL_BF7615CM 0x0100

// STC8H 0x02xx
#define CHIP_MODEL_STC8H_GENERIC 0x0200
#define CHIP_MODEL_STC8H8K64U 0x0201

#endif
