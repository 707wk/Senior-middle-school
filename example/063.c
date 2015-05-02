//63、请用指针法输出一个数组的所有元素
#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},*p;
	for(p=a;p<a+10;printf("%3d",*p++));
	getchar();
	return 0;
}