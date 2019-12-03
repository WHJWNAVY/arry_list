/*
 * Include Files
 */
#include <string.h>
#include "arry_list.h"
/*
 * Symbol Definition
 */

/*
 * Data Declaration
 */
al_data_t   gv_alTable[AL_TABLE_MAX];   /* Arry list table*/
uint32_t      gv_alCurNum = 0;            /* Current arry list num */

/*
 * Macro Definition
 */
#define AL_DATE_SIZE                                    \
    (sizeof(al_data_t))
#define AL_TABLE_SET(var)                               \
    do{memset(&(var),0xFF,AL_DATE_SIZE);}while(0)
#define AL_TABLE_CLR(var)                               \
    do{memset(&(var),0,AL_DATE_SIZE);}while(0)
#define AL_TABLE_CPY(dst, src)                          \
    do{memcpy(&(dst),&(src),AL_DATE_SIZE);}while(0)

#define IS_AL_TABLE_EQUAL(s1, s2)                       \
    (memcmp(&(s1),&(s2),AL_DATE_SIZE) == 0)

/*
 * Function Declaration
 */

/*******************************************************************************
 *
 * Command Common Functions
 *
 ******************************************************************************/
static int32_t _al_table_add_idx(uint32_t idx, al_data_t *tbl)
{
    if((idx < 0) || (idx > AL_TABLE_MAX))
        return AL_ERR_DATE_RANGE;
    if(tbl == NULL)
        return AL_ERR_POINT_NULL;
    if(gv_alCurNum >= AL_TABLE_MAX)// Table is full, can't insert anyone.
        return AL_ERR_TABLE_FULL;

    AL_TABLE_CPY(gv_alTable[idx], (*tbl));
    gv_alCurNum++;
    return AL_ERR_OK;
}

static int32_t _al_table_del_idx(uint32_t idx)
{
    uint32_t i = 0;
    if((idx < 0) || (idx >= gv_alCurNum))
        return AL_ERR_DATE_RANGE;
    if(gv_alCurNum == 0) // Table is empty, nothing to delete.
        return AL_ERR_DATE_EMPTY;

    if(idx == (gv_alCurNum-1))
    {//last one
        AL_TABLE_CLR(gv_alTable[idx]);
    }
    else
    {
        AL_TABLE_CPY(gv_alTable[idx], gv_alTable[gv_alCurNum-1]);//copy last to idx
        AL_TABLE_CLR(gv_alTable[gv_alCurNum-1]);// clear last one
    }
    gv_alCurNum--;
    return AL_ERR_OK;
}

static int32_t _al_table_find(al_data_t *tbl, uint32_t *idx)
{
    uint32_t i = 0;
    al_data_t cmp_t;
    AL_TABLE_CLR(cmp_t);
    if((tbl == NULL) || (idx == NULL))
        return AL_ERR_POINT_NULL;
    if(IS_AL_TABLE_EQUAL(cmp_t, (*tbl)))
        return AL_ERR_DATE_EMPTY;// table is empty!

    for(i=0; i<gv_alCurNum; i++)
    {
        if(IS_AL_TABLE_EQUAL(gv_alTable[i], (*tbl)))
        {
            *idx = i;
            return AL_ERR_OK;
        }
    }
    *idx = AL_ERR_FAIL;
    return AL_ERR_FAIL;
}


/*****************************************************************************
 �� �� ��  : al_table_init
 ��������  : ��ʼ�������б�
 �������  : void  
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_init(void)
{
    uint32_t i = 0;
    for(i=0; i<AL_TABLE_MAX; i++)
    {
        AL_TABLE_CLR(gv_alTable[i]);
    }
    return AL_ERR_OK;
}

/*****************************************************************************
 �� �� ��  : al_table_add
 ��������  : ����������һ��Ԫ��
 �������  : al_data_t *tbl  :��Ҫ���ӵ�Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_add(al_data_t *tbl)
{
    al_data_t cmp_t;
    AL_TABLE_CLR(cmp_t);

    if(tbl == NULL)
        return AL_ERR_POINT_NULL;
    if(IS_AL_TABLE_EQUAL(cmp_t, (*tbl)))
        return AL_ERR_DATE_EMPTY;// table is empty!

    if(_al_table_add_idx(gv_alCurNum, tbl) != AL_ERR_OK)
        return AL_ERR_FAIL;
    else
        return AL_ERR_OK;
}

/*****************************************************************************
 �� �� ��  : al_table_del
 ��������  : ɾ������ָ����Ԫ��
 �������  : al_data_t *tbl  :��Ҫɾ����Ԫ��
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_del(al_data_t *tbl)
{
    uint32_t idx = 0;
    al_data_t cmp_t;
    AL_TABLE_CLR(cmp_t);

    if(tbl == NULL)
        return AL_ERR_POINT_NULL;
    if(IS_AL_TABLE_EQUAL(cmp_t, (*tbl)))
        return AL_ERR_DATE_EMPTY;// table is empty!

    if(_al_table_find(tbl, &idx) == AL_ERR_OK)
        return (_al_table_del_idx(idx));
    else
        return AL_ERR_FAIL;
}

/*****************************************************************************
 �� �� ��  : al_table_modify
 ��������  : �޸ı���ָ����Ԫ��
 �������  : al_data_t *fr_tbl  :��Ҫ���޸ĵ�Ԫ��
             al_data_t *to_tbl  :�޸ĺ��Ԫ�ص�ֵ
 �������  : ��
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_modify(al_data_t *fr_tbl, al_data_t *to_tbl)
{
    uint32_t idx = 0;
    al_data_t cmp_t;
    AL_TABLE_CLR(cmp_t);

    if((fr_tbl == NULL) || (to_tbl == NULL))
        return AL_ERR_POINT_NULL;
    if(IS_AL_TABLE_EQUAL(cmp_t, (*fr_tbl)))
        return AL_ERR_DATE_EMPTY;// table is empty!
    #if 1
    if(IS_AL_TABLE_EQUAL(cmp_t, (*fr_tbl)))
        return AL_ERR_DATE_EMPTY;// table is empty!
    #endif

    if(_al_table_find(fr_tbl, &idx) == AL_ERR_OK)
    {
        AL_TABLE_CPY(gv_alTable[idx], (*to_tbl));
        return AL_ERR_OK;
    }
    else
    {
        return AL_ERR_FAIL;
    }
}

/*****************************************************************************
 �� �� ��  : al_table_get_byidx
 ��������  : ͨ������ȡ�ñ��е�Ԫ��
 �������  : uint32_t idx      :Ԫ������
 �������  : al_data_t *tbl  :ȡ�õ�Ԫ��ֵ
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_get_byidx(uint32_t idx, al_data_t *tbl)
{
    uint32_t idx_t = idx;
    #if 1
    if((idx < 0) || (idx >= gv_alCurNum))
        return AL_ERR_DATE_RANGE;
    #else
    idx_t = (idx < 0) ? 0 : ((idx >= gv_alCurNum) ? gv_alCurNum : idx);
    #endif

    if(tbl == NULL)
        return AL_ERR_POINT_NULL;

    AL_TABLE_CPY((*tbl), gv_alTable[idx_t]);

    return AL_ERR_OK;
}

/*****************************************************************************
 �� �� ��  : al_table_get_num
 ��������  : ��ȡ����Ԫ�ظ���
 �������  : ��
 �������  : uint32_t *num  :���е�Ԫ�ظ���
 �� �� ֵ  : 

*****************************************************************************/
int32_t al_table_get_num(uint32_t *num)
{
    if(num == NULL)
        return AL_ERR_POINT_NULL;
    *num = gv_alCurNum;
    return AL_ERR_OK;
}