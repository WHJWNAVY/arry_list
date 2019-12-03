#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "arry_list.h"

int main(void)
{
    uint32_t i = 0, num = 0, max = AL_TABLE_MAX;
    al_data_t xm = {0, "XiaoMing"};
    al_data_t xm_t;
    al_table_init();
    for(i=0; i<max; i++)
    {
        xm.id = i;
        al_table_add(&xm);
    }
    #if 1
    al_table_get_num(&num);
    for(i=0; i<num; i++)
    {
        al_table_get_byidx(i, &xm_t);
        printf("AA------IDX: %-6d; ID: %-6d; NAME: %-10s\n", i, xm_t.id, xm_t.name);
    }
    #endif
    printf("--------------------------------------------------\n\n");

    for(i=0; i<max; i++)
    {
        xm.id = i*2 + 1;
        al_table_del(&xm);
    }
    #if 1
    al_table_get_num(&num);
    for(i=0; i<num; i++)
    {
        al_table_get_byidx(i, &xm_t);
        printf("BB------IDX: %-6d; ID: %-6d; NAME: %-10s\n", i, xm_t.id, xm_t.name);
    }
    #endif
    printf("--------------------------------------------------\n\n");
    // getchar();
    // getchar();
    return 0;
}