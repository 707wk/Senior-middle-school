//59������ʵ�飬��p��һ��ָ����������*p++,*(p++),(*p)++,&*p�����á�
#include<stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10},*p;
	p=a;
	printf("p=a : %d",*p);
	p=a;
	printf("\n*p++   = %d",*p++);printf("֮�� *p = %d\n",*p);
	p=a;
	printf("*(p++) = %d",*(p++));printf("֮�� *p = %d\n",*p);
	p=a;
	printf("(*p)++ = %d",(*p)++);printf("֮�� *p = %d\n",*p);
	p=a;
	printf("&*p = %d: p = %d\n",&*p,p);
	getchar();
	return 0;
}