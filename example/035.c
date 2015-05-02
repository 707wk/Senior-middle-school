//35、编程实现strlen函数的功能。
#include<stdio.h>
int fun(char *a)
{
	if(*a==0)return 0;
	return fun(a+1)+1;
}
int main()
{
	char a[]="this is a book.";
	printf("%d",fun(a));
	getchar();
	return 0;
}