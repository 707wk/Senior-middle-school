//9����/4��1-1/3+1/5-1/7+����ʽ��еĽ���ֵ��ֱ��ĳһ��ľ���ֵС��0.0001Ϊֹ��
#include<stdio.h>
int main()
{
	int tmp=1;
	float sum=0,n;
	for(n=1;1/n>=1e-4;n+=2,tmp=-tmp)
		sum=sum+tmp*1.0/n;
	printf("%f",sum*4);
	getchar();
	return 0;
}