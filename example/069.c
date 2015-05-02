//69、用指针法实现循环右移，循环左移算法。
#include<stdio.h>
void left(int a[])
{
	int temp=*a,*p;
	for(p=a;p<a+9;p++)*p=*(p+1);
	*p=temp;
}
void right(int a[])
{
	int temp=*(a+9),*p;
	for(p=a+9;p>a;p--)*p=*(p-1);
	*p=temp;
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},i;
	for(i=0,printf("\n");i<10;printf("%3d",a[i++]));
	left(a);
	for(i=0,printf("\n");i<10;printf("%3d",a[i++]));
	right(a);
	for(i=0,printf("\n");i<10;printf("%3d",a[i++]));
	getchar();
	return 0;
}
