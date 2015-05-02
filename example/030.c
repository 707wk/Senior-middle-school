//30、编程实现二维数组周边元素之和。
#include<stdio.h>
#define M 5
int main()
{
	int a[M][M],i,j,sum=0;
	for(i=0;i<M;i++)
		for(j=0;j<M;j++)
		{
			a[i][j]=i*M+j+1;
			sum+=a[i][j];
		}
	for(i=0;i<M;i++,printf("\n"))
		for(j=0;j<M;printf("%3d",a[i][j++]));
	printf(" sum = %3d",sum);
	getchar();
	return 0;
}