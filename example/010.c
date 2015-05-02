//10、求1+2!/2-3!/3+4!/4-5!/5……前10项的和。 
#include<stdio.h>
int fun1(int n)
{
	if(n==1)return 1;
	return fun1(n-1)*n;
}
float fun(int n)
{
	float sum=1,i;
	int tmp=1;
	for(i=2;i<=n;i++,tmp=-tmp)
		sum=sum+tmp*fun1(i)/i;
	return sum;
}
int main()
{
	printf("%f\n",fun(10));
	getchar();
	return 0;
}