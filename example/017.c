//17、用迭代法求一个数的平方根。
#include<stdio.h>
float fabs(float n)
{
	if(n<0)return -n;
	return n;
}
float fun(float n)
{
	float x1=1,x2=(x1+n/x1)/2;
	while(fabs(x2-x1)>1e-4)
	{
		x1=x2;
		x2=(x1+n/x1)/2;
	}
	return x2;
}
int main()
{
	float num;
	scanf("%f",&num);
	printf("%f",fun(num));
	getchar();
	getchar();
	return 0;
}