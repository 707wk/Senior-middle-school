#include<stdio.h>
int main()
{
	int i,j,n=1,m=0;
	printf("载入数据中-\b");
	while(1)
	{
		m++;
		for(i=0;i<5000;i++)
		for(j=0;j<5000;j++);
			if(n>4)n=1;
			switch(n)
			{
				case 1:
					printf("\\\b");
				break;
				case 2:
					printf("|\b");
				break;
				case 3:
					printf("/\b");
				break;
				case 4:
					printf("-\b");
				break;
			}
			n++;
		if(m%7==0)
		{
			printf("=");
			m=1;
		}
	}
	getchar();
	return 0;
}
