/**************************************
 *FILE    :main.c
 *PROJECT :030
 *AUTHOR  :707wk
 *CREATED :9/16/2013
***************************************/
#include<stdio.h>
int main(int argc, char *argv[])
{
system("clear");
char z;
int a;
for(z='a';z<='d';z++)
{
//a=((z!='b')&&(z=='d'))+((z!='b')&&(z=='d'))+((z!='a')&&(z=='b'))+(z!='d');
a=(z!='d');
//if(a==0||a==4)break;
printf("%d\n",a);
}
printf("The thief is %c\n",z-32);
getchar();
	return 0;
}
