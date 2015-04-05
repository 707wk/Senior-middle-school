/*----------------------------------------------
File: G:\soft\temp\data_ranking\main.c
Date: 2014-3-23 18:01:47
Author: 1174843091@qq.com
----------------------------------------------*/
#include <stdio.h>
#include <malloc.h>
#include "data_ranking.h"

int main()
{
    if(data_read())
    {
        printf("数据出错\n");
    }
    else
    {
        printf("处理完毕\n");
    }
    getchar();
    return 0;
}
