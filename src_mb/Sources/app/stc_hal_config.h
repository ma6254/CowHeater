/*******************************************************************************
 *
 * Keil����ͼ�λ����ý���
 * �����·� ��Configuration Wizard�� ѡ�
 * �����ֶ��༭
 * ���ļ��̶�ΪGBK��GB18030��GB3212����һ�֣��������ΪUTF-8�����������ʽ
 *
 * The file is fixed to one of GBK, GB18030, GB3212, please do not save as UTF-8 or other encoding formats
 *
 ******************************************************************************/

#ifndef STC_CONFIG_H
#define STC_CONFIG_H
//-------------- <<< Use Configuration Wizard in Context Menu >>> --------------

// <o> оƬ�ͺ�
// <0xF783=> STC8H8K64U
#define CHIP_MODEL 0xF783

// <o> оƬ��װ
// <0x0320=> LQFP32
// <0x032C=> LQFP40
// <0x0330=> LQFP48
// <0x0340=> LQFP64
// <0x0420=> QFN32
// <0x0008=> SOP8
// <0x1914=> TSSOP20
#define CHIP_FOOTPRINT 0x1914

// <o.0..48000000> ����Ƶ��
// <i> ���ʹ�����þ���ѡ������STC-ISP�����õ�IRCƵ��
// <i> ���ʹ�����þ�����дʵ��Ƶ��
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
