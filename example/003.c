//3����Sn=a+aa+aaa+��+aa��aaa����n��a��ֵ֮������a��һ�����֡�
#include<stdio.h>
int main()
{
	long s=0,n,a,t;
	scanf("%d%d",&a,&n);
	for(t=a;n>0;n--)
	{
		s=s+a;
		a=a*10+t;
	}
	printf("%ld",s);
	getchar();
	getchar();
	return 0;
}
