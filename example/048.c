//48、用递归调用求5!
#include<stdio.h>
int fun(int n)
{
	if(n==1)return 1;
	return fun(n-1)*n;
}
int main()
{
	printf("%d",fun(5));
	getchar();
	return 0;
}