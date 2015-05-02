//38、将两个已排好序的字符数组合并成一个字符数组，并输出。
#include<stdio.h>
void fun(char *a,char *b)
{
	char tmp[100],*p=a,*q;
	for(q=tmp;*a&&*b;q++)
	{
		if(*a<*b)*q=*a++;
		else *q=*b++;
	}
	if(*a)for(;*q++=*a++;);
	else for(;*q++=*b++;);
	strcpy(p,tmp);
}
int main()
{
	char a[100]="13579",b[]="2468";
	fun(a,b);
	puts(a);
	getchar();
	return 0;
}