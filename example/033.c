//33�����ʵ��strupr�����Ĺ��ܡ�
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