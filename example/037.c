//37��ɾ��һ���ַ������е�ĳһָ���ַ����������
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