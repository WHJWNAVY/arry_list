#ifndef __ARRY_LIST_H_
#define __ARRY_LIST_H_

/*
 * Include Files
 */
#include "type.h"
/*
 * System Config Define
 */
#define AL_TABLE_MAX        1000
/*
 * Symbol Definition
 */
typedef struct al_date_s
{
    //for user, you can modify it as yourself.
    uint32 id;
    int8 name[20];
}al_date_t;

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
extern int32 al_table_init(void);

/*****************************************************************************
 �� �� ��  : al_table_add
 ��������  : ����������һ��Ԫ��
 �������  : al_date_t *tbl  :��Ҫ���ӵ�Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32 al_table_add(al_date_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_del
 ��������  : ɾ������ָ����Ԫ��
 �������  : al_date_t *tbl  :��Ҫɾ����Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32 al_table_del(al_date_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_modify
 ��������  : �޸ı���ָ����Ԫ��
 �������  : al_date_t *fr_tbl  :��Ҫ���޸ĵ�Ԫ��
             al_date_t *to_tbl  :�޸ĺ��Ԫ�ص�ֵ
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
extern int32 al_table_modify(al_date_t *fr_tbl, al_date_t *to_tbl);

/*****************************************************************************
 �� �� ��  : al_table_get_byidx
 ��������  : ͨ������ȡ�ñ��е�Ԫ��
 �������  : uint32 idx      :Ԫ������
 �������  : al_date_t *tbl  :ȡ�õ�Ԫ��ֵ
 �� �� ֵ  : 

*****************************************************************************/
extern int32 al_table_get_byidx(uint32 idx, al_date_t *tbl);

/*****************************************************************************
 �� �� ��  : al_table_get_num
 ��������  : ��ȡ����Ԫ�ظ���
 �������  : ��
 �������  : uint32 *num  :���е�Ԫ�ظ���
 �� �� ֵ  : 

*****************************************************************************/
extern int32 al_table_get_num(uint32 *num);

#endif