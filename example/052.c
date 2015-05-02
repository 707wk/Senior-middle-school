//52、编写自定义函数并使用顺序查找法求一个数在已知数组中的位置，若找到返回该数，否则返回-1.
#include<stdio.h>
int fun(int *a,int n)
{
	int *p;
	for(p=a;p<a+10;p++)if(*p==n)return p-a+1;
	return -1;
}
int main()
{
	int a[10]={3,5,6,7,8,2,1,4,9,10},n;
	scanf("%d",&n);
	printf("%d",fun(a,n));
	getchar();
	getchar();
	return 0;
}