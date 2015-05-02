//64、请用指针法逆序存放一个数组
#include<stdio.h>
int main()
{
	char a[]="this is a book.",*p,*q,tmp;
	for(p=q=a;*q;q++);
	for(q--;p<q;p++,q--)
	{
		tmp=*p;
		*p=*q;
		*q=tmp;
	}
	puts(a);
	getchar();
	return 0;
}