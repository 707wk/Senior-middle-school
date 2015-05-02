/**************************************
 *FILE    :main.c
 *PROJECT :003
 *AUTHOR  :
 *CREATED :4/10/2013
***************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char c;
fp=fopen("text","r");
while((c=fgetc(fp))!=EOF)
{
putchar(c);
}
}
