//32�����ʵ���ַ����ȽϺ����Ĺ��ܡ�
#include<stdio.h>
int fun(char a[],char b[])
{
	for(;*a==*b&&*a&&*b;a++,b++);
	return *a-*b;
}
int main()
{
	char a[]="this",b[]="that";
	printf("%d",fun(a,b));
	getchar();
	return 0;
}