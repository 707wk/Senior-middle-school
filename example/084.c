//84、用指针来处理一个数列，如 1,1,2,2,3,4,3,5,6,5 处理后得到 1,2,3,4,5,6 得到一数列中唯一的值。
#include<stdio.h>
int main()
{
	int a[]={1,1,2,2,3,4,3,5,6,5},*p,*q,*head=a,i=0;
	for(p=a;p<a+10;p++)
	{
		for(q=a;q<a+10;q++)
			if(*p==*q)break;
		if(p==q){*head++=*p;i++;}
	}
	for(p=a;p<a+i;p++)
		printf("%3d",*p);
	getchar();
	return 0;
}
