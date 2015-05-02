/**************************************
 *FILE    :main.c
 *PROJECT :yhsj
 *AUTHOR  :707wk
 *CREATED :5/7/2013
***************************************/
#include<stdio.h>
void fun()
{
  int i,j,a[10][10];
  for(i=0;i<10;i++)
    for(j=0;j<i;j++)
    {
      if(j==0||j==i-1)a[i][j]=1;
      else
      {
        a[i][j]=a[i-1][j]+a[i-1][j-1];
      }
  }
  for(i=0;i<10;i++)
  {
    for(j=0;j<i;j++)
    {
      printf(" %d ",a[i][j]);
    }
    printf("\n");
  }
}
int main(int argc, char *argv[])
{
fun();
}
