//32、编程实现字符串比较函数的功能。
#include<stdio.h>
int fun(char a[],char b[])
{
	for(;*a==*b&&*a&&*b;a++,b++);
	return *a-*b;
}
int main()
{
	char a[]="this",b[]="that";
	printf("%d",fun(a,b));
	getchar();
	return 0;
}