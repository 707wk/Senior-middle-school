//58������ָ����Ϊ��������ʽ������ʵ���������Ľ������㷨��
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
	printf("a b\n����ǰ:\n%d:%d\n",a,b);
	fun(&a,&b);
	printf("������:\n%d:%d\n",a,b);
	getchar();
	return 0;
}