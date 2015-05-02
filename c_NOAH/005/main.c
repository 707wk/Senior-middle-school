/**************************************
 *FILE    :main.c
 *PROJECT :005
 *AUTHOR  :
 *CREATED :4/11/2013
***************************************/
#include<stdio.h>
#include"curses.h"
int main(int argc, char *argv[])
{
char c;
do
{
c=getch();
printf("%d",c);
}while(1);
}
