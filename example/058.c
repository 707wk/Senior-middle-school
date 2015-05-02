//58、请用指针作为函数的形式参数，实现两个数的交换的算法。
#include<stdio.h>
void fun(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
int main()
{
	int a=3,b=5;
	printf("a b\n交换前:\n%d:%d\n",a,b);
	fun(&a,&b);
	printf("交换后:\n%d:%d\n",a,b);
	getchar();
	return 0;
}