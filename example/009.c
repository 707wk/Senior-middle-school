//9、π/4≈1-1/3+1/5-1/7+…公式求π的近似值，直到某一项的绝对值小于0.0001为止。
#include<stdio.h>
int main()
{
	int tmp=1;
	float sum=0,n;
	for(n=1;1/n>=1e-4;n+=2,tmp=-tmp)
		sum=sum+tmp*1.0/n;
	printf("%f",sum*4);
	getchar();
	return 0;
}