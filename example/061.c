//61、请用指针变量的自增运算来输出一个整型数组的所有元素。
#include<stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10},*p;
	for(p=a;p<a+10;printf("%3d",*p++));
	getchar();
	return 0;
}