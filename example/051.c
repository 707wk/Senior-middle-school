//51、用自定义函数给十数排升序。
#include<stdio.h>
void fun(int *a)
{
	int *p,*q,tmp;
	for(p=a;p<a+9;p++)
		for(q=p+1;q<a+10;q++)
			if(*p>*q)
			{
				tmp=*q;
				*q=*p;
				*p=tmp;
			}
}
int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1},i;
	fun(a);
	for(i=0;i<10;printf("%3d",a[i++]));
	getchar();
	return 0;
}