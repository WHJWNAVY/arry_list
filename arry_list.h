#ifndef __ARRY_LIST_H_
#define __ARRY_LIST_H_

/*
 * Include Files
 */
#include <stdint.h>
#include <stdbool.h>
/*
 * System Config Define
 */
#define AL_TABLE_MAX        1000
/*
 * Symbol Definition
 */
typedef struct al_data_e
{
    /* vvvv DON'T MODIFY vvvv */
    uint32_t id;
    /* ^^^^ DON'T MODIFY ^^^^ */

    //for user, you can modify it as yourself.
    int8_t name[20];
}al_data_t;

typedef enum al_error_s
{
    AL_ERR_FAIL = -1,
    AL_ERR_OK,
    AL_ERR_POINT_NULL,
    AL_ERR_DATE_EMPTY,
    AL_ERR_TABLE_FULL,
    AL_ERR_DATE_RANGE,
}al_error_t;
/*
 * Data Declaration
 */

/*
 * Macro Definition
 */
 
/*
 * Function Declaration
 */

/*******************************************************************************
 *
 * Command Common Functions
 *
 ******************************************************************************/

/*****************************************************************************
 �� �� ��  : al_table_init
 ��������  : ��ʼ�������б�
 �������  : void  
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_init(void);

/*****************************************************************************
 �� �� ��  : al_table_add
 ��������  : ����������һ��Ԫ��
 �������  : al_data_t *tbl  :��Ҫ���ӵ�Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_add(al_data_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_del
 ��������  : ɾ������ָ����Ԫ��
 �������  : al_data_t *tbl  :��Ҫɾ����Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_del(al_data_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_modify
 ��������  : �޸ı���ָ����Ԫ��
 �������  : al_data_t *fr_tbl  :��Ҫ���޸ĵ�Ԫ��
             al_data_t *to_tbl  :�޸ĺ��Ԫ�ص�ֵ
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_modify(al_data_t *fr_tbl, al_data_t *to_tbl);

/*****************************************************************************
 �� �� ��  : al_table_get_byidx
 ��������  : ͨ������ȡ�ñ��е�Ԫ��
 �������  : uint32_t idx      :Ԫ������
 �������  : al_data_t *tbl  :ȡ�õ�Ԫ��ֵ
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_get_byidx(uint32_t idx, al_data_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_get_num
 ��������  : ��ȡ����Ԫ�ظ���
 �������  : ��
 �������  : uint32_t *num  :���е�Ԫ�ظ���
 �� �� ֵ  : 

*****************************************************************************/
extern int32_t al_table_get_num(uint32_t *num);

#endif
