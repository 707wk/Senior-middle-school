//40、求一串字符中的单词数量。
#include<stdio.h>
int fun(char *a)
{
	int sum=0,tmp=1;
	for(;*a;a++)
	{
		if(*a!=' ')
		{
			if(tmp==1)
			{
				sum++;
				tmp=0;
			}
		}
		else tmp=1;
	}
	return sum;
}
int main()
{
	char a[]="this is a book";
	printf("\"%s\" have %d word",a,fun(a));
	getchar();
	return 0;
}