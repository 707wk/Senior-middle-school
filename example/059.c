//59、请做实验，设p是一个指针变量，体会*p++,*(p++),(*p)++,&*p的作用。
#include<stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10},*p;
	p=a;
	printf("p=a : %d",*p);
	p=a;
	printf("\n*p++   = %d",*p++);printf("之后 *p = %d\n",*p);
	p=a;
	printf("*(p++) = %d",*(p++));printf("之后 *p = %d\n",*p);
	p=a;
	printf("(*p)++ = %d",(*p)++);printf("之后 *p = %d\n",*p);
	p=a;
	printf("&*p = %d: p = %d\n",&*p,p);
	getchar();
	return 0;
}