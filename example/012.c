//12、求菲波列茨数列并输出。
#include<stdio.h>
int main()
{
	int i=1,j=1,n;
	printf("%d %d ",i,j);
	for(n=3;n<10;n+=2)
	{
		i=i+j;
		j=i+j;
		printf("%d %d ",i,j);
	}
	getchar();
	return 0;
}