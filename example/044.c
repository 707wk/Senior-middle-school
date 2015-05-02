//44、请用函数实现字符串的循环右移操作。
//例如:abcde右移一位后变成eabcd,若调用函数 fun(x,2)则x字符串将变成deabc
#include<stdio.h>
void fun(char *a,int n)
{
	char *p,tmp;
	for(;n>0;n--)
	{
		for(p=a;*p;p++);
		for(p--,tmp=*p;p>a;p--)*p=*(p-1);
		*p=tmp;
	}
}
int main()
{
	int n;
	char a[]="this is a book.";
	scanf("%d",&n);
	fun(a,n);
	puts(a);
	getchar();
	getchar();
	return 0;
}
