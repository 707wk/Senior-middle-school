//1�����ʵ��������������Լ������С�������������������Ϸ�������
#include<stdio.h>
int main()
{
	int max,min,n,m;
	scanf("%d%d",&n,&m);
	max=n>m?n:m;
	min=n>m?m:n;
	for(;max%n!=0||max%m!=0;max++);
	for(;n%min!=0||m%min!=0;min--);
	printf("%3d%3d",max,min);
	getchar();
	getchar();
	return 0;
}
