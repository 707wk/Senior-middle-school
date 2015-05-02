//68、用指针法实现数组元素的逆序存放。
#include<stdio.h>
void fun(int a[])
{
	int *p=a,*q=a+9,temp;
	while(p<q)
	{
		temp=*q;
		*q=*p;
		*p=temp;
		p++;
		q--;
	}
}
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)a[i]=i+1;
	fun(a);
	for(i=0;i<10;printf("%3d",a[i++]));
	getchar();
	return 0;
}
