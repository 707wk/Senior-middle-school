//29、编程实现一维数组元素的循环右移操作。例如：1 2 3 4 5 6 向右移动一个位置后变成 6 1 2 3 4 5。
#include<stdio.h>
void fun(int a[])
{
	int tmp=*(a+5),*p;
	for(p=a+5;p>a;p--)*p=*(p-1);
	*p=tmp;
}
int main()
{
	int a[]={1,2,3,4,5,6},i;
	fun(a);
	for(i=0;i<6;printf("%3d",a[i++]));
	getchar();
	return 0;
}