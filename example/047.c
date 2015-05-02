//47、用递归调用求一个字符串的长度
#include<stdio.h>
int fun(char *a)
{
	if(!(*a))return 0;
	return fun(a+1)+1;
}
int main()
{
	char a[]="this is a book.";
	printf("%d",fun(a));
	getchar();
	return 0;
}