/**************************************
 *FILE    :main.c
 *PROJECT :007
 *AUTHOR  :707wk
 *CREATED :4/22/2013
***************************************/
#include<stdio.h>
#define M 10
#define N 10
void fun(int a[][N],int m,int n,int x)
{
  int i;
  if(m<=0||n<=0)return ;
  for(i=0;i<m;i++)a[i][0]=x++;
  for(i=1;i<n;i++)a[m-1][i]=x++;
  for(i=m-2;i>=0&&n>1;i--)a[i][n-1]=x++;
  for(i=n-2;i>=1&&m>1;i--)a[0][i]=x++;
  fun(*(a+1)+1,m-2,n-2,x);
}
void fun1(int a[][N],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++,printf("\n"))
    for(j=0;j<n;j++)
        printf("%3d",a[i][j]);
}
int main(int argc, char *argv[])
{
  int a[M][N]={0};
  fun(a,M,N,1);
  fun1(a,M,N);
}
