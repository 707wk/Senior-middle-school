#include <stdio.h>
#include <stdlib.h>
#include "ip_analysis.h"

int main()
{
    char str_ip[100];
    printf("������ip��ַ����������(����:192.168.1.2/24)\n");
_continuation:
    gets(str_ip);
    if(ip_analysis(str_ip))
    {
        printf("ip��ַ���������������������������!\n");
        goto _continuation;
    }
    getchar();
    return 0;
}
