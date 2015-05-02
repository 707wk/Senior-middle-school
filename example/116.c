//X116.c利用指针求子串在母串中出现的次数。
#include<stdio.h>
int fun1(char *a,char *b)
{
	while(*a==*b){a++;b++;}
	if(*b)return 0;
	return 1;
}
int fun(char *a,char *b)
{
	int n=0;
	for(;*a;a++)
	if(fun1(a,b))n++;
	return n;
}
int main()
{
	char a[100]="this is a book.",b[20];
	gets(b);
	printf("%d",fun(a,b));
	getchar();
	return 0;
}
