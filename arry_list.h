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
 函 数 名  : al_table_init
 功能描述  : 初始化数组列表
 输入参数  : void  
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_init(void);

/*****************************************************************************
 函 数 名  : al_table_add
 功能描述  : 往表中增加一个元素
 输入参数  : al_data_t *tbl  :需要增加的元素
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_add(al_data_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_del
 功能描述  : 删除表中指定的元素
 输入参数  : al_data_t *tbl  :需要删除的元素
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_del(al_data_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_modify
 功能描述  : 修改表中指定的元素
 输入参数  : al_data_t *fr_tbl  :需要被修改的元素
             al_data_t *to_tbl  :修改后的元素的值
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_modify(al_data_t *fr_tbl, al_data_t *to_tbl);

/*****************************************************************************
 函 数 名  : al_table_get_byidx
 功能描述  : 通过索引取得表中的元素
 输入参数  : uint32_t idx      :元素索引
 输出参数  : al_data_t *tbl  :取得的元素值
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_get_byidx(uint32_t idx, al_data_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_get_num
 功能描述  : 获取表中元素个数
 输入参数  : 无
 输出参数  : uint32_t *num  :表中的元素个数
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_get_num(uint32_t *num);

#endif
