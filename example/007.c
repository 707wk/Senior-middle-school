//7、一球从100米高度自由下落，每次落地后返回原 高度的一半，再落下。求它在第10次落地时共 经过多少米？第10次反弹多高？(用两种方法)
#include<stdio.h>
void fun1()
{
	float s=0,h=100;
	int n=10;
	for(;n>0;n--)
	{
		s=s+h/2*3;
		h=h/2;
	}
	printf("%f\n%f\n",s-h,h);
}
float fun(int n,float h)
{
	if(n==1)return h;
	return fun(n-1,h/2)+h;
}
float fun2(int n,float h)
{
	if(n==1)return h/2;
	return fun2(n-1,h/2);
}
int main()
{
	fun1();
	printf("%f\n%f\n",fun(10,200)-100,fun2(10,100));
	getchar();
	return 0;
}
