/*******************************************************************************
 *
 * Keil辅助图形化配置界面
 * 请点击下方 “Configuration Wizard” 选项卡
 * 请勿手动编辑
 * 该文件固定为GBK、GB18030、GB3212其中一种，请勿另存为UTF-8或其他编码格式
 *
 * The file is fixed to one of GBK, GB18030, GB3212, please do not save as UTF-8 or other encoding formats
 *
 ******************************************************************************/

#ifndef STC_CONFIG_H
#define STC_CONFIG_H
//-------------- <<< Use Configuration Wizard in Context Menu >>> --------------

// <o> 芯片型号
// <0xF783=> STC8H8K64U
#define CHIP_MODEL 0xF783

// <o> 芯片封装
// <0x0320=> LQFP32
// <0x032C=> LQFP40
// <0x0330=> LQFP48
// <0x0340=> LQFP64
// <0x0420=> QFN32
// <0x0008=> SOP8
// <0x1914=> TSSOP20
#define CHIP_FOOTPRINT 0x1914

// <o.0..48000000> 晶振频率
// <i> 如果使用内置晶振：选择您在STC-ISP中设置的IRC频率
// <i> 如果使用外置晶振：填写实际频率
// < 6000000=> 6MHz
// <11059200=> 11.0592MHz
// <12000000=> 12MHz
// <16000000=> 16MHz
// <20000000=> 20MHz
// <24000000=> 24MHz
// <25000000=> 25MHz
// <40000000=> 40MHz
#define CHIP_FREQ 24000000

#include "port_route.h"

//-------------------- <<< end of configuration section >>> --------------------

#endif /* End of STC_CONFIG_H */
