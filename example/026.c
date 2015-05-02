//26、编程实现strcat函数的功能。
#include<stdio.h>
void strc(char a[],char b[])
{
	while(*a)a++;
	for(;*a++=*b++;);
}
int main()
{
	char a[100]="this is a ",b[]="book.";
	strc(a,b);
	puts(a);
	getchar();
	return 0;
}