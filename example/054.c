//54、用编译预理的办法求两个数的最大者。
#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
	printf("%d",max(3,5));
	getchar();
	return 0;
}