/**************************************
 *FILE    :main.c
 *PROJECT :009
 *AUTHOR  :
 *CREATED :4/30/2013
***************************************/
/*Ë­ÔÚËµ»Ñ*/
#include<stdio.h>
int main(int argc, char *argv[])
{
  int a,b,c;
  for(a=0;a<=1;a++)
    for(b=0;b<=1;b++)
      for(c=0;c<=1;c++)
        if((a&&!b||!a&&b)&&(b&&!c||!b&&c)&&(c&&a+b==0||!c&a+b!=0))
        {
          printf("abc\n%d%d%d\n",a,b,c);
        }
}
