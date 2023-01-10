#include <STC8H.h>
#include "hal_sys.h"

/*******************************************************************************
 * @brief 初始化
 * @param None
 * @return None
 ******************************************************************************/
void sys_init(void)
{
}

/*******************************************************************************
 * @brief 主函数，程序入口
 * @param None
 * @return None
 ******************************************************************************/
void main(void)
{
    hal_init();
    sys_init();
    while (1)
    {
    }
}
