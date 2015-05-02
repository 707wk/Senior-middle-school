#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	for(;;)
	{
		i=system("key.exe");
		printf("%d\n",i);
		i=0;
		getch();
	}
}
