/**************************************
 *FILE    :main.c
 *PROJECT :012
 *AUTHOR  :
 *CREATED :5/15/2013
***************************************/
/*option函数读写文件内容*/
#include<stdio.h>
#include"option.h"
int main(int argc, char *argv[])
{
char s[100]="a";
option('a','r',s);
printf("%s\n",s);
printf("%ld\n",option('b','r',s));
printf("%ld\n",option('c','r',s));
printf("%ld\n",option('d','r',s));
printf("%ld\n",option('e','r',s));
printf("%ld\n",option('f','r',s));
printf("%ld\n",option('g','r',s));
}
