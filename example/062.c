//62、请用递归调用法求杨辉三角.
#include<stdio.h>
int fun(int i,int j)
{
	if(i==j||j==0)return 1;
	return fun(i-1,j-1)+fun(i-1,j);
}
int main()
{
	int i,j;
	for(i=0;i<10;i++,printf("\n"))
		for(j=0;j<=i;j++)
			printf("%4d",fun(i,j));
	getchar();
	return 0;
}