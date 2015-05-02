/**************************************
 *FILE    :main.c
 *PROJECT :023
 *AUTHOR  :
 *CREATED :9/2/2013
***************************************/
#include<stdio.h>
int max(int a)
{
int i,j,b;
scanf("%d",&b);
if(b==0)return 0;
for(i=1;i<=a||i<=b;i++)if((a%i==0)&&(b%i==0))j=i;
return j;
}
int main(int argc, char *argv[])
{
int a,i;
scanf("%d",&a);
for(;i=max(a);)a=i;
printf("%d",a);
}
