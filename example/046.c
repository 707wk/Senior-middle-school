//46���õݹ������1��100�ĺ�
#include<stdio.h>
int fun(int n)
{
	if(n==1)return 1;
	return fun(n-1)+n;
}
int main()
{
	printf("%d",fun(100));
	getchar();
	return 0;
}