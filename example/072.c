//72、用指针法来做耶稣的叛徒的算法.
#include<stdio.h>
int main()
{
	int *p,a[13],n=0,num=13;
	for(p=a;p<a+13;p++)*p=1;
	for(p=a;num>1;p++)
	{
		if(p>a+12)p=a;
		if(*p)n++;
		if(n==3){*p=0;num--;n=0;}
	}
	for(p=a;p<a+13;p++)
		if(*p)printf("%d",p-a+1);
	getchar();
	return 0;
}
