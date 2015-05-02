/**************************************
 *FILE    :main.c
 *PROJECT :015
 *AUTHOR  :
 *CREATED :6/2/2013
***************************************/
#include<stdio.h>
int main(int argc, char *argv[])
{
  int a[5][5]={1},i=1,j=0,m=2,flag=0;
  a[i][j]=m;
  while(m<15)
  {
    m++;
    if(flag==0){i--;j++;}
    else {i++;j--;}
    if(i<0){i=0;flag=1;}
    if(j<0){j=0;flag=0;}
    a[i][j]=m;
  }
  for(i=0;i<5;printf("\n"),i++)for(j=0;j<5;j++)if(a[i][j])printf("%d ",a[i][j]);
}
