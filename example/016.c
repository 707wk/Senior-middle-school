//16、用二分法求方程2*x*x*x-4*x*x+3*x-6方程的根。
#include<stdio.h>
#include<math.h>
float fang(float x)
{
return 2*x*x*x-4*x*x+3*x-6;
}
float fun1(int m,int n)
{
	float x1=m,x2=n,tmp;
	while(fang((x1+x2)/2)!=0)
	{
		tmp=(x1+x2)/2;
		if(fang(x1)*fang(tmp)<0)x2=tmp;
		else if(fang(x1)*fang(tmp)>0)x1=tmp;
	}
	return (x1+x2)/2;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("方程2*x*x*x-4*x*x+3*x-6=0的解是x=%f",fun1(m,n));
	printf("\n%f\n",fang(fun1(m,n)));
	getchar();
	getchar();
	return 0;
}