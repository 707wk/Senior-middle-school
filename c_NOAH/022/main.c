/**************************************
 *FILE    :main.c
 *PROJECT :022
 *AUTHOR  :
 *CREATED :9/2/2013
***************************************/
#include<stdio.h>
int max(int a,int b)
{
int i,j;
for(i=1;i<=a||i<=b;i++)
{
if((a%i==0)&&(b%i==0))j=i;
}
return j;
}
int min(int a,int b)
{
int i;
for(i=(a>b?a:b);;i++)
{
if((i%a==0)&&(i%b==0)){return i;break;}
}
}
int main(int argc, char *argv[])
{
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
printf("%d %d",max(max(a,b),c),min(min(a,b),c));
}
