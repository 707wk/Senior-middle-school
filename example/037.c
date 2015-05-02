//37、删除一个字符数组中的某一指定字符，并输出。
#include<stdio.h>
void fun(char *a,char c)
{
	char *p=a;
	while(*p)
	{
		if(*p!=c)*a++=*p++;
		else p++;
	}
	*a='\0';
}
int main()
{
	char a[]="this is a book.";
	fun(a,'i');
	puts(a);
	getchar();
	return 0;
}