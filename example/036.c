//36、编程实现将已排好序的字符数组a，将b数组中的元素按a数组中的规律插入到a。
#include<stdio.h>
void fun(char *a,char *b)
{
	char *p=a,*q,tmp;
	strcat(a,b);
	for(;*(p+1);p++)
		for(q=p+1;*q;q++)
			if(*p>*q)
			{
				tmp=*p;
				*p=*q;
				*q=tmp;
			}
}
int main()
{
	char a[100]="13579",b[]="82460";
	fun(a,b);
	puts(a);
	getchar();
	return 0;
}