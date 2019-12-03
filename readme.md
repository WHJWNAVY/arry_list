# array list api

## DEBUG
```bash
AA------IDX: 0     ; ID: 0     ; NAME: XiaoMing
AA------IDX: 1     ; ID: 1     ; NAME: XiaoMing
AA------IDX: 2     ; ID: 2     ; NAME: XiaoMing
AA------IDX: 3     ; ID: 3     ; NAME: XiaoMing
AA------IDX: 4     ; ID: 4     ; NAME: XiaoMing
AA------IDX: 5     ; ID: 5     ; NAME: XiaoMing
AA------IDX: 6     ; ID: 6     ; NAME: XiaoMing
AA------IDX: 7     ; ID: 7     ; NAME: XiaoMing
AA------IDX: 8     ; ID: 8     ; NAME: XiaoMing
AA------IDX: 9     ; ID: 9     ; NAME: XiaoMing
AA------IDX: 10    ; ID: 10    ; NAME: XiaoMing
AA------IDX: 11    ; ID: 11    ; NAME: XiaoMing
AA------IDX: 12    ; ID: 12    ; NAME: XiaoMing
AA------IDX: 13    ; ID: 13    ; NAME: XiaoMing
AA------IDX: 14    ; ID: 14    ; NAME: XiaoMing
AA------IDX: 15    ; ID: 15    ; NAME: XiaoMing
AA------IDX: 16    ; ID: 16    ; NAME: XiaoMing
AA------IDX: 17    ; ID: 17    ; NAME: XiaoMing
AA------IDX: 18    ; ID: 18    ; NAME: XiaoMing
AA------IDX: 19    ; ID: 19    ; NAME: XiaoMing
AA------IDX: 20    ; ID: 20    ; NAME: XiaoMing
AA------IDX: 21    ; ID: 21    ; NAME: XiaoMing
AA------IDX: 22    ; ID: 22    ; NAME: XiaoMing
AA------IDX: 23    ; ID: 23    ; NAME: XiaoMing
AA------IDX: 24    ; ID: 24    ; NAME: XiaoMing
AA------IDX: 25    ; ID: 25    ; NAME: XiaoMing
AA------IDX: 26    ; ID: 26    ; NAME: XiaoMing
AA------IDX: 27    ; ID: 27    ; NAME: XiaoMing
AA------IDX: 28    ; ID: 28    ; NAME: XiaoMing
AA------IDX: 29    ; ID: 29    ; NAME: XiaoMing
AA------IDX: 30    ; ID: 30    ; NAME: XiaoMing
AA------IDX: 31    ; ID: 31    ; NAME: XiaoMing
AA------IDX: 32    ; ID: 32    ; NAME: XiaoMing
AA------IDX: 33    ; ID: 33    ; NAME: XiaoMing
AA------IDX: 34    ; ID: 34    ; NAME: XiaoMing
AA------IDX: 35    ; ID: 35    ; NAME: XiaoMing
AA------IDX: 36    ; ID: 36    ; NAME: XiaoMing
AA------IDX: 37    ; ID: 37    ; NAME: XiaoMing
AA------IDX: 38    ; ID: 38    ; NAME: XiaoMing
AA------IDX: 39    ; ID: 39    ; NAME: XiaoMing
AA------IDX: 40    ; ID: 40    ; NAME: XiaoMing
AA------IDX: 41    ; ID: 41    ; NAME: XiaoMing
AA------IDX: 42    ; ID: 42    ; NAME: XiaoMing
AA------IDX: 43    ; ID: 43    ; NAME: XiaoMing
AA------IDX: 44    ; ID: 44    ; NAME: XiaoMing
AA------IDX: 45    ; ID: 45    ; NAME: XiaoMing
AA------IDX: 46    ; ID: 46    ; NAME: XiaoMing
AA------IDX: 47    ; ID: 47    ; NAME: XiaoMing
AA------IDX: 48    ; ID: 48    ; NAME: XiaoMing
AA------IDX: 49    ; ID: 49    ; NAME: XiaoMing
--------------------------------------------------

BB------IDX: 0     ; ID: 0     ; NAME: XiaoMing
BB------IDX: 1     ; ID: 34    ; NAME: XiaoMing
BB------IDX: 2     ; ID: 2     ; NAME: XiaoMing
BB------IDX: 3     ; ID: 48    ; NAME: XiaoMing
BB------IDX: 4     ; ID: 4     ; NAME: XiaoMing
BB------IDX: 5     ; ID: 26    ; NAME: XiaoMing
BB------IDX: 6     ; ID: 6     ; NAME: XiaoMing
BB------IDX: 7     ; ID: 46    ; NAME: XiaoMing
BB------IDX: 8     ; ID: 8     ; NAME: XiaoMing
BB------IDX: 9     ; ID: 36    ; NAME: XiaoMing
BB------IDX: 10    ; ID: 10    ; NAME: XiaoMing
BB------IDX: 11    ; ID: 44    ; NAME: XiaoMing
BB------IDX: 12    ; ID: 12    ; NAME: XiaoMing
BB------IDX: 13    ; ID: 28    ; NAME: XiaoMing
BB------IDX: 14    ; ID: 14    ; NAME: XiaoMing
BB------IDX: 15    ; ID: 42    ; NAME: XiaoMing
BB------IDX: 16    ; ID: 16    ; NAME: XiaoMing
BB------IDX: 17    ; ID: 32    ; NAME: XiaoMing
BB------IDX: 18    ; ID: 18    ; NAME: XiaoMing
BB------IDX: 19    ; ID: 40    ; NAME: XiaoMing
BB------IDX: 20    ; ID: 20    ; NAME: XiaoMing
BB------IDX: 21    ; ID: 30    ; NAME: XiaoMing
BB------IDX: 22    ; ID: 22    ; NAME: XiaoMing
BB------IDX: 23    ; ID: 38    ; NAME: XiaoMing
BB------IDX: 24    ; ID: 24    ; NAME: XiaoMing
--------------------------------------------------
```

## API

```c
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
typedef struct al_date_s
{
    //for user, you can modify it as yourself.
    uint32_t id;
    int8_t name[20];
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
 输入参数  : al_date_t *tbl  :需要增加的元素
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_add(al_date_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_del
 功能描述  : 删除表中指定的元素
 输入参数  : al_date_t *tbl  :需要删除的元素
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_del(al_date_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_modify
 功能描述  : 修改表中指定的元素
 输入参数  : al_date_t *fr_tbl  :需要被修改的元素
             al_date_t *to_tbl  :修改后的元素的值
 输出参数  : 无
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_modify(al_date_t *fr_tbl, al_date_t *to_tbl);

/*****************************************************************************
 函 数 名  : al_table_get_byidx
 功能描述  : 通过索引取得表中的元素
 输入参数  : uint32_t idx      :元素索引
 输出参数  : al_date_t *tbl  :取得的元素值
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_get_byidx(uint32_t idx, al_date_t *tbl);

/*****************************************************************************
 函 数 名  : al_table_get_num
 功能描述  : 获取表中元素个数
 输入参数  : 无
 输出参数  : uint32_t *num  :表中的元素个数
 返 回 值  : 

*****************************************************************************/
extern int32_t al_table_get_num(uint32_t *num);

#endif

```