//50�����Զ��庯��ʵ���������Ļ���
#include<stdio.h>
void fun(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
int main()
{
	int a=3,b=5;
	fun(&a,&b);
	printf("%3d%3d",a,b);
	getchar();
	return 0;
}