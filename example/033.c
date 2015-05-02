//33、编程实现strupr函数的功能。
#include<stdio.h>
void fun(char *a)
{
	for(;*a;a++)
		if(*a>='a'&&*a<='z')*a=*a-32;
}
int main()
{
	char a[]="This ia a book.";
	fun(a);
	puts(a);
	getchar();
	return 0;
}