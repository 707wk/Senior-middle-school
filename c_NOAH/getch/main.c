#include<stdio.h>
#include"getch.h"
int main()
{
char c;
while(1)
{
c=getch();
printf("%d\n",c);
}
/*
int a[10][40]={0},m,n,i=0,j=0,tmp;
for(n=0;n<10;n++)
for(m=0;m<40;m++)
a[n][m]=35;
a[0][0]='กั';
system("clear");
do
{
if(c==65&&i>0)
{
tmp=a[i-1][j];a[i-1][j]=a[i][j];a[i][j]=tmp;i--;
}
if(c==66&&i<9)
{
tmp=a[i+1][j];a[i+1][j]=a[i][j];a[i][j]=tmp;i++;
}
if(c==68&&j>0)
{
tmp=a[i][j-1];a[i][j-1]=a[i][j];a[i][j]=tmp;j--;
}
if(c==67&&j<39)
{
tmp=a[i][j+1];a[i][j+1]=a[i][j];a[i][j]=tmp;j++;
}
for(n=0;n<10;n++,printf("\n"))
{
for(m=0;m<40;m++)
printf("%c",a[n][m]);
}

system("clear");
}while(c!='q');
*/
}
