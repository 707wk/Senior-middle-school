/**************************************
 *FILE    :main.c
 *PROJECT :018
 *AUTHOR  :707wk
 *CREATED :9/10/2013
***************************************/
#include<stdio.h>
int main(int argc, char *argv[])
{
int a,b;
char c,d;
for(;;){
system("clear");
scanf("%d%c%d%c",&a,&c,&b,&d);
if(c=='+')c='-';
else if(c=='-')c='+';
else printf("error\n");
if(c=='+'||c=='-')printf("%d%c%d%c\n",a,c,b,d);
getchar();
getchar();
}
	return 0;
}
