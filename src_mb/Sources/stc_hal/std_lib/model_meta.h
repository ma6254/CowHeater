#ifndef _H_HAL_MODEL_META_
#define _H_HAL_MODEL_META_

/*******************************************************************************
 * ENUM CHIP_FOOTPRINT
 ******************************************************************************/

// LQFP 0x11**
#define CHIP_FOOTPRINT_LQFP32 0x1120
#define CHIP_FOOTPRINT_LQFP44 0x112C
#define CHIP_FOOTPRINT_LQFP48 0x1130
#define CHIP_FOOTPRINT_LQFP64 0x1140

// SOP 0x00**
#define CHIP_FOOTPRINT_SOP8 0x1808
#define CHIP_FOOTPRINT_SOP16 0x1810
#define CHIP_FOOTPRINT_SOP20 0x1814
#define CHIP_FOOTPRINT_SOP24 0x1818
#define CHIP_FOOTPRINT_SOP28 0x181C

// SSOP 0x01**

// TSSOP 0x02**
#define CHIP_FOOTPRINT_TSSOP20 0x1914

// QFN 0x04**
#define CHIP_FOOTPRINT_QFN20 0x1614
#define CHIP_FOOTPRINT_QFN32 0x1620

/*******************************************************************************
 * ENUM CHIP_MODEL
 ******************************************************************************/

// STC8H 0x02xx
#define CHIP_MODEL_STC8H8K64U 0xF783

#endif
