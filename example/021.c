//21����9����վ�������ж����ֲ�ͬ�ĳ�Ʊ��
#include<stdio.h>
int main()
{
	int i,j,sum=0;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if(i!=j)sum++;
	printf("%d",sum);
	getchar();
	return 0;
}