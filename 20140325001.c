/*----------------------------------------------
Writer: Tomohiko Sakamoto
File: G:\soft\02\183.c
Date: 2014-3-25 16:20:27
Author: xx@xxx.com
计算今天星期几
----------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

/* 0 = Sunday */
int dayofweek(int y,int m,int d)
{
    static int t[]=
    {
        0,3,2,5,0,3,5,1,4,6,2,4 
    }
    ;
    y-=m<3 ;
    return(y + y/4 - y/100 + y/400 + t[m-1] + d)%7 ;
}

int main()
{
    switch(dayofweek(2014,3,25))
    {
        case 0 :
        printf("7");
        break ;
        case 1 :
        printf("1");
        break ;
        case 2 :
        printf("2");
        break ;
        case 3 :
        printf("3");
        break ;
        case 4 :
        printf("4");
        break ;
        case 5 :
        printf("5");
        break ;
        case 6 :
        printf("6");
        break ;
    }
    getchar();
    return 0 ;
}
