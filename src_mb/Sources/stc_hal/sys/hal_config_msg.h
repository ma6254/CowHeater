#ifndef HAL_CONFIG_MSG_H
#define HAL_CONFIG_MSG_H

#if CHIP_FREQ == 12000000
#pragma message("芯片时钟频率：12Mhz")
#elif CHIP_FREQ == 16000000 /* End of CHIP_FREQ == 12000000 */
#pragma message("芯片时钟频率：16Mhz")
#elif CHIP_FREQ == 24000000 /* End of CHIP_FREQ == 16000000 */
#pragma message("芯片时钟频率：24Mhz")
#else /* End of CHIP_FREQ == 24000000 */
#pragma message("芯片时钟频率：")
#pragma message(CHIP_FREQ)
#endif /* End of Special SysFreq */

#endif /* End of HAL_CONFIG_MSG_H */
