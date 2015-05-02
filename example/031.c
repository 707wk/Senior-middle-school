//31¡¢±à³ÌÇóÑî»ÔÈı½Ç
#include<stdio.h>
#define M 10
int main()
{
	int a[M][M],i,j;
	for(i=0;i<M;i++,printf("\n"))
		for(j=0;j<=i;j++)
		{
			if(i==j||j==0)a[i][j]=1;
			else a[i][j]=a[i-1][j]+a[i-1][j-1];
			printf("%4d",a[i][j]);
		}
	getchar();
	return 0;
}
