//76、用指向普通元素的指针输出二维数组元素的所有值。
#include<stdio.h>
int main()
{
	int a[4][4],*p;
	for(p=*a;p<*a+16;p++)
		printf("%3d",*p=p-*a+1);
	getchar();
	return 0;
}

