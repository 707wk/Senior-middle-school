//19、用循环实现国际象棋的棋盘。
#include<stdio.h>
#define n 10
int main()
{
	int i,j;
	for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<n;j++)
			if(i%2)
			{
				if(j%2!=1)printf(" %c ",1);
				else printf("%c",2);
			}
			else 
			{
				if(j%2!=1)printf(" %c ",2);
				else printf("%c",1);
			}
	getchar();
	return 0;
}