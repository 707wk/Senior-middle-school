//X119.c利用指针删除母串中的指定子串
#include<stdio.h>
int fun1(char *a)
{
	if(*a)return fun1(a+1)+1;
	else return 0;
}
int fun2(char *a,char *b)
{
	while(*a==*b){a++;b++;}
	if(*b)return 0;
	return 1;
}
void fun(char *a,char *b,int n)
{
	char *head=a;
	while(*a)
	{
		if(fun2(a,b))a=a+n-1;
		else *head++=*a;
		a++;
	}
	*head='\0';
}
int main()
{
	char a[]="this is a book",b[20];
	gets(b);
	fun(a,b,fun1(b));
	puts(a);
	getchar();
	return 0;
}
