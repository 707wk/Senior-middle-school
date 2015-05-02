//45、用递归调用求汉诺塔
#include<stdio.h>
void move(char a,char b)
{
	printf("%c -> %c\n",a,b);
}
void fun(char a,char b,char c,int n)
{
	if(n==1)move(a,c);
	else
	{
		fun(a,c,b,n-1);
		move(a,c);
		fun(b,a,c,n-1);
	}
}
int main()
{
	fun('a','b','c',3);
	getchar();
	return 0;
}