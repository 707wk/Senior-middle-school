//57、请做一个二维数组不初始化，看里面的值是否为随机数的实验。
#include<stdio.h>
#define M 5
int main()
{
	int a[M][M],i,j;
	for(i=0;i<M;i++,printf("\n"))
		for(j=0;j<M;printf(" %d ",a[i][j++]));
	getchar();
	return 0;
}