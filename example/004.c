//4¡¢Çó £¬£¨¼´Çó1!+2!+3!+4!+5!+¡­+20!£©
#include<stdio.h>
long fun1(int n)
{
	if(n==1)return 1;
	return fun1(n-1)*n;
}
long fun(int n)
{
	if(n==1)return 1;
	return fun(n-1)+fun1(n);
}
int main()
{
	printf("%ld",fun(20));
	getchar();
	return 0;
}