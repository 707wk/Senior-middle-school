#include <stdio.h>
#include <stdlib.h>
#include "ip_analysis.h"

int main()
{
    char str_ip[100];
    printf("请输入ip地址及子网掩码(例如:192.168.1.2/24)\n");
_continuation:
    gets(str_ip);
    if(ip_analysis(str_ip))
    {
        printf("ip地址或子网掩码输入错误，请重新输入!\n");
        goto _continuation;
    }
    getchar();
    return 0;
}
