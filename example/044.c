//44�����ú���ʵ���ַ�����ѭ�����Ʋ�����
//����:abcde����һλ����eabcd,�����ú��� fun(x,2)��x�ַ��������deabc
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
