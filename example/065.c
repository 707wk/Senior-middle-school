//65������ָ�뷨��һ��һά�����е�����ߣ�������ߵ��±겢�����
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