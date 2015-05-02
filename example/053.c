//53、编程实现得到一个数组中的不重复数，例如1,1,1,2,2,3,3,4,5,4 则最终结果为1,2,3,4,5
#include<stdio.h>
int fun(int *a,int n)
{
	int *p,*q,*head=a,sum=0;
	for(p=a;p<a+10;p++)
	{
		for(q=a;q<a+10;q++)
			if(*q==*p)break;
		if(q==p)
		{
			sum++;
			*head++=*p;
		}
	}
	return sum;
}
int main()
{
	int a[]={1,1,1,2,2,3,3,4,5,4},i,n;
	n=fun(a,sizeof(a)/sizeof(int));
	for(i=0;i<n;printf("%3d",a[i++]));
	getchar();
	return 0;
}