/**************************************
 *FILE    :main.c
 *PROJECT :019
 *AUTHOR  :
 *CREATED :9/13/2013
***************************************/
#include<stdio.h>
int main(int argc, char *argv[])
{
int s=0,x;
for(x=1;x<=100;s=s+x++);
printf("%d\n",s);
	return 0;
}
