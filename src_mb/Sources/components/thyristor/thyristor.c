#include "thyristor.h"

/*******************************************************************************
 * @brief ��ʼ����բ�ܿ��ƽṹ��
 * @param t ��բ�ܽṹ��ʵ��ָ��
 * @param pin ���ƽ�
 * @return None
 ******************************************************************************/
void triac_init(triac_t *t, gpio_writer_handler fn)
{
    t->gate_pin_writer = fn;
    t->duty = 0;
    t->cycle = 0;

    triac_off(t);
}

/*******************************************************************************
 * @brief ���þ�բ��������ʵȼ�
 * @param t ��բ�ܽṹ��ʵ��ָ��
 * @param level ���ʵȼ�
 * @return None
 ******************************************************************************/
// void triac_set_duty(triac_t *t, triac_level_t level)
// {
//     if (level > triac_level_full)
//         level = triac_level_full;
//     t->duty = level;
// }

// void triac_duty_inc(triac_t *t, int8_t level)
// {
//     int8_t tmp_duty = (int8_t)(t->duty) + level;

//     if (tmp_duty < 0)
//         tmp_duty = 0;
//     else if (tmp_duty > TRIAC_LEVEL_FULL)
//         tmp_duty = TRIAC_LEVEL_FULL;

//     t->duty = tmp_duty;
// }

/*******************************************************************************
 * @brief ��ʱ���ص�������20ms����һ��
 * @param t ��բ�ܽṹ��ʵ��ָ��
 * @return None
 ******************************************************************************/
void triac_timer_handler(triac_t *t)
{
    t->cycle++;

    if (t->cycle == TRIAC_LEVEL_FULL)
    {
        t->cycle = 0;

        if (t->duty == TRIAC_LEVEL_0)
            triac_off(t);
        else
            triac_on(t);
    }
    else if (t->cycle == t->duty)
    {
        triac_off(t);
    }
}

/*******************************************************************************
 * @brief �ⲿ�жϻص��������е����ʱ�ᴥ������
 * @param t ��բ�ܽṹ��ʵ��ָ��
 * @return None
 ******************************************************************************/
// void triac_exint_handler(triac_t *t)
// {
//     if (t->cycle == (triac_level_full - 1))
//     {
//         t->cycle = 0;
//         triac_off(t);
//     }

//     if (t->duty > t->cycle)
//         triac_on(t);

//     t->cycle++;
// }
