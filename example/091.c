//91、有一数列，该数列的第1，2项分别为0和1，以后每个奇数编号的项是
//前两项和的绝对值，偶数编号的项是前两项的差的绝对值。生成的20个数存
//在一维数组x中，并按每行4项的形式输出。试编程
#include<stdio.h>
int fun(int n)
{
	if(n<0)return -n;
	return n;
}
int main()
{
	int a[20]={0,1},i;
	for(i=2;i<20;i++)
	{
		if((i+1)%2)a[i]=fun(a[i-1]-a[i-2]);
		else a[i]=fun(a[i-1]+a[i-2]);
	}
	for(i=0;i<20;i++)
	{
		if(i%4==0&&i!=0)printf("\n");
		printf("%3d",a[i]);
	}
	getchar();
	return 0;
}
