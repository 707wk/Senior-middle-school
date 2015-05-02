//3、求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字。
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
