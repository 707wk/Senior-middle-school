//22、用数组来求菲波列次数列。
#include<stdio.h>
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
		if(i==0||i==1)a[i]=1;
		else a[i]=a[i-1]+a[i-2];
	for(i=0;i<10;i++)
		printf("%4d",a[i]);
	getchar();
	return 0;
}