//67、请编程实现子网划分
#include<stdio.h>
void fun(int a[],int b[])
{
	int n;
	if(b[1]==0)
	{
		n=256-b[0];
		printf("网络地址：:%d.%d.%d.%d\n广播地址：%d.%d.%d.%d",a[0]/n*n,0,0,0,a[0]/n*n+n-1,255,255,255);
	}
	else if(b[2]==0)
	{
		n=256-b[1];
		printf("网络地址：:%d.%d.%d.%d\n广播地址：%d.%d.%d.%d",a[0],a[1]/n*n,0,0,a[0],a[1]/n*n+n-1,255,255);
	}
	else if(b[3]==0)
	{
		n=256-b[2];
		printf("网络地址：:%d.%d.%d.%d\n广播地址：%d.%d.%d.%d",a[0],a[1],a[2]/n*n,0,a[0],a[1],a[2]/n*n+n-1,255);
	}
	else
	{
		n=256-b[3];
		printf("网络地址：:%d.%d.%d.%d\n广播地址：%d.%d.%d.%d",a[0],a[1],a[2],a[3]/n*n,a[0],a[1],a[2],a[3]/n*n+n-1);
	}
}
int main()
{
	int a[4],b[4];
	printf("输入IP地址：\n");
	scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
	printf("输入子网掩码：\n");
	scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
	fun(a,b);
	getchar();
	getchar();
	return 0;
}
