//14、请编程将一个十进数转变成6进制数输出。
#include<stdio.h>
int fun(int n)
{
	int num=1,sum=0;
	for(;n;n=n/6,num=num*10)
		sum=sum+num*(n%6);
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fun(n));
	getchar();
	getchar();
	return 0;
}