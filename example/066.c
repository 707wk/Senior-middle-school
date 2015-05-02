//66、请用指针法求超过平均值的元素的个数
#include<stdio.h>
int main()
{
	int a[10]={45,67,93,56,25,73,48,34,55,88},*p,n=0;
	float aver=0;
	for(p=a;p<a+10;aver+=*p++);
	for(aver/=10,p=a;p<a+10;p++)
		if(*p>aver)n++;
	printf("%d",n);
	getchar();
	return 0;
}