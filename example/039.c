//39、求三个字符串中的最大字符串。
#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="zhangfei",
		 b[]="guanyu",
		 c[]="zhaoyun",*p=b;
	if(strcmp(a,b)>0)p=a;
	if(strcmp(p,c)<0)p=c;
	puts(p);
	getchar();
	return 0;
}
