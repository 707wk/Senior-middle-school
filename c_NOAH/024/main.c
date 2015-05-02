/**************************************
 *FILE    :main.c
 *PROJECT :024
 *AUTHOR  :707wk
 *CREATED :9/4/2013
***************************************/
/*求n个数的最大公约数*/
#include<stdio.h>
#include"getch.h"
int max(int a,char *p)
{
	int i,j,b=0;
	char c;
	while((c=getch())!=' '&&c!=13)
	{
		b=b*10+c-'0';
		printf("%c",c);
	}
	if(c=='\r')*p='\r';
	printf("%c",c);
	for(i=1;i<=a&&i<=b;i++)
		if((a%i==0)&&(b%i==0))j=i;
	return j;
}
int main(int argc, char *argv[])
{
	int i,s=0;
	char m,c;
	while((c=getch())!='\r'&&c!=' ')
	{
		s=s*10+c-'0';
		printf("%c",c);
	}
	printf("%c",c);
	for(;i=max(s,&m);){s=i;if(m=='\r')break;}
	printf("\n%d\n",s);
}
