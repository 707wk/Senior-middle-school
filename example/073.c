//73、用二维数组的指针输出一个二维数组。
#include<stdio.h>
int main()
{
	int a[4][4],(*p)[4],*q;
	for(p=a;p<a+4;p++,printf("\n"))
		for(q=*p;q<*p+4;q++)
			printf("%3d",*q=q-*a+1);
		getchar();
		return 0;
}
