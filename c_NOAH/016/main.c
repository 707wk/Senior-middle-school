/**************************************
 *FILE    :main.c
 *PROJECT :016
 *AUTHOR  :
 *CREATED :9/8/2013
***************************************/
#include<stdlib.h>
#include<stdio.h>
int zm(char a)
{
if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))return 1;
return 0;
}
int main(int argc, char *argv[])
{
char a[]={0},*p;
int n;
system("reset");
gets(a);
p=a;
for(n=zm(*p);*p!='\0'&&*(p+1)!='\0';p++)
if((!zm(*p))&&zm(*(p+1)))n++;
printf("一共有%d个单词\n",n);
return 0;
}
