/**************************************
 *FILE    :main.c
 *PROJECT :025
 *AUTHOR  :707wk
 *CREATED :6/9/2013
***************************************/
#include<stdio.h>
int main(void)
{
  int a[9][9]={0},i,j,k=1,t=0;
  //while(t<=9/2)
  while(k<=81)
  {
     for(i=t,j=t;j<9-t;j++,k++)a[i][j]=k;
     for(j=9-t-1,i=t+1;i<9-t;i++,k++)a[i][j]=k;
     for(i=9-t-1,j=9-t-2;j>=t;j--,k++)a[i][j]=k;
     for(j=t,i=9-t-2;i>t;i--,k++)a[i][j]=k;
     t++;
  }
  for(i=0;i<9;i++,printf("\n"))
    for(j=0;j<9;j++)printf("%3d",a[i][j]);
  return 0;
}

