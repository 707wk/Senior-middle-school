//43、请用弦截法求x*x*x-5*x*x+16*x-80的根,其弦截公式为x=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1))
#include<stdio.h>
float fab(float tmp)
{
	if(tmp<0)return -tmp;
	return tmp;
}
float fang(int x)
{
	return x*x*x-5*x*x+16*x-80;
}
float fun(int m,int n)
{
	float x1=m,x2=n,tmp=(x1*fang(x2)-x2*fang(x1))/(fang(x2)-fang(x1));
	while(fab(fang(tmp))>1e-4)
	{
		if(fang(tmp)*fang(x1)>0)x1=tmp;
		else if(fang(tmp)*fang(x2)>0)x2=tmp;
		tmp=(x1*fang(x2)-x2*fang(x1))/(fang(x2)-fang(x1));
	}
	return tmp;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("x*x*x-5*x*x+16*x-80 的解 x= %f\n",fun(m,n));
	getchar();
	getchar();
	return 0;
}