//27�����ʵ��strcpy�����Ĺ��ܡ�
#include<stdio.h>
void strc(char a[],char b[])
{
	for(;*a++=*b++;);
}
int main()
{
	char a[100],b[]="this is a book.";
	strc(a,b);
	puts(a);
	getchar();
	return 0;
}