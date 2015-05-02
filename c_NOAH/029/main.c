/**************************************
 *FILE    :main.c
 *PROJECT :029
 *AUTHOR  :Ê¢Ðñ¶«
 *CREATED :9/16/2013
***************************************/
#include<stdio.h>
int main(int argc, char *argv[])
{
//system("clear");
int a[4]={0},i,n;
for(i=0;i<4;i++)
{
a[i]=1;
if(((a[1]+a[3])==1)&&((a[1]+a[2])==1)&&((a[0]+a[1])==1)&&(a[3]!=1))break;
else a[i]=0;
}
printf("thief is No. %d\n",i+1);
getchar();
    return 0;
}
