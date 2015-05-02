//65、请用指针法求一个一维数组中的最大者，及最大者的下标并输出。
#include<stdio.h>
int main()
{
	int a[10]={1,9,8,4,5,6,3,10,2,7},*p,*q;
	for(p=q=a;p<a+10;p++)
		if(*q<*p)q=p;
	printf("max is %d\nit is at %d\n",*q,q-a);
	getchar();
	return 0;
}