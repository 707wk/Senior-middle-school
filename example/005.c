//5、打印出所有"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该本身。
#include<stdio.h>
int main()
{
	int n=100,a[3];
	for(;n<1000;n++)
	{
		a[0]=n/100;
		a[1]=n/10%10;
		a[2]=n%10;
		if((a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2])==n)printf("%d\n",n);
	}
	getchar();
	return 0;
}