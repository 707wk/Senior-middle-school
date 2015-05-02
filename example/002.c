//2、编程实现求三个数的最大公约数及最小公倍数。
#include<stdio.h>
int main()
{
	int max,min,n,m,o;
	scanf("%d%d%d",&n,&m,&o);
	max=n>m?(n>o?n:o):(m>o?m:o);
	min=n>m?(m>o?o:m):(n>o?o:n);
	for(;max%n!=0||max%m!=0||max%o!=0;max++);
	for(;n%min!=0||m%min!=0||o%min!=0;min--);
	printf("%3d%3d",max,min);
	getchar();
	getchar();
	return 0;
}
