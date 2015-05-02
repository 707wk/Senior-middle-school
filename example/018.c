//18、用循环实现九九乘法表。
#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<10;i++,printf("\n"))
		for(j=1;j<=i;j++)
			printf("%d=%d*%d ",i*j,i,j);
	getchar();
	return 0;
}