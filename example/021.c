//21、有9个火车站，请问有多少种不同的车票。
#include<stdio.h>
int main()
{
	int i,j,sum=0;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if(i!=j)sum++;
	printf("%d",sum);
	getchar();
	return 0;
}