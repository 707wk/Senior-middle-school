//81、用指针法求一个字符串的长度。
#include<stdio.h>
int fun(char *a)
{
	if(!*a)return 0;
	return fun(a+1)+1;
}
int main()
{
	printf("%d",fun("this is a book."));
	getchar();
	return 0;
}
