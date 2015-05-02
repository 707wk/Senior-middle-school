//28、编程实现二维数组的转置。
#include<stdio.h>
#define M 5
void pr(int a[][M])
{
	int i,j;
	for(i=0;i<M;i++,printf("\n"))
		for(j=0;j<M;printf("%3d",a[i][j++]));
}
void fun(int a[][M])
{
	int i,j,tmp;
	for(i=0;i<M;i++)
		for(j=0;j<i;j++)
		{
			tmp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=tmp;
		}
}
int main()
{
	int a[M][M],i,j;
	for(i=0;i<M;i++)
		for(j=0;j<M;j++)
			a[i][j]=i*M+j+1;
	fun(a);
	pr(a);
	getchar();
	return 0;
}