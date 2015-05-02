/**************************************
 *FILE    :main.c
 *PROJECT :031
 *AUTHOR  :707wk
 *CREATED :9/18/2013
***************************************/
/*3 6 1 8 8 6 4*/
#include<stdio.h>
#define n 100
int main(int argc, char *argv[])
{
	system("clear");
	int a[n]={0},i,s=0;
	a[0]=3;
	a[1]=6;
	for(i=2;i<n;i++)
	{
		s=a[i-1]*a[i-2];
		if(s/10)
		{
			a[i]=s/10;
			a[i+1]=s%10;
			i=i+1;
		}
		else a[i]=s;
	}
	for(i=0;i<n;i++)
	{
		if(!(i%10))printf("\n");
		printf("%3d",a[i]);
	}
	getchar();
	return 0;
}
