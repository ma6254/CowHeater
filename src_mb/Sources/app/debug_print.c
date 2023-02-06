#include "debug_print.h"
#include "hal_timer.h"
#include "hal_uart.h"

#include "load.h"
#include "sensor.h"

#define DEBUG_PRINT_TASK_TIME ((time_t)10)

data uint32_t debug_print_task_tmp_time = 0;

void debug_print_task(void)
{
    if (hal_delay_ms(&debug_print_task_tmp_time, DEBUG_PRINT_TASK_TIME))
    {
        // printf("%ld hello world!!!\r\n", hal_uptime);
        // printf("%lu,\r\n", hal_uptime);
        // printf("%bd,\r\n", ccc,);
        // ccc++;
        // printf("%u,%u,\r\n", adc_aaa, adc_119);
        // printf("%u,", adc_119);
        printf("%bu,", G_LOAD.triac.duty * 10);
        printf("%u,", G_LOAD.target_temp);
        // printf("%u,", adc_ntc);
        printf("%d,", gSensor.ntc_temp);
        // printf("%u,", adc_aaa);
        // printf("%d,", heat_temp);
        printf("%d,", gSensor.heat_temp);

        printf("%d,", G_LOAD.power_scale);
        // printf("%lu,", zn_time);
        // printf("%d,", zn_max_temp);
        // printf("%d,", zn_min_temp);
        printf("\r\n");
    }
}

/*******************************************************************************
 * C:/Keil_v5/C51/LIB/PUTCHAR.C
 * https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Library-Reference/Reference/printf
 *
 * %d   int     Signed decimal number.
 * %u   uint    Unsigned decimal number.
 * %o   uint    Unsigned octal number.
 * %x   uint    Unsigned hexadecimal number using "0123456789abcedf".
 * %X   uint    Unsigned hexadecimal number using "0123456789ABCDEF".
 * %c   char    A single character.
 * %s   *       A string of characters terminated by a null character ('\0').
 *
 * Note:
 * - The total number of bytes that may be passed to this function is limited
 *   due to the memory restrictions imposed by the 8051. A maximum of 15 bytes
 *   may be passed in SMALL or COMPACT model. A maximum of 40 bytes may be
 *   passed in LARGE model.
 *
 * long type: L or l
 * char type: B or b
 *
 ******************************************************************************/
char putchar(char c)
{
    // while (!TI)
    //     ;
    // TI = 0;
    // return (SBUF = c);

    hal_uart1_write_byte(c);
    return c;
}
