//13、输入一个数判断该数是否为回文数。（例如：1221就是一个回文数）
#include<stdio.h>
int fun(char a[])
{
char *p,*q;
p=q=a;
for(;*q;q++);
q--;
for(;p<=q;p++,q--)
if(*p!=*q)return 0;
return 1;
}
int main()
{
char c,a[100],*p;
p=a;
while((c=getchar())!='\n')
*p++=c;
*p=0;
if(fun(a))printf("%s是回文数",a);
else printf("%s不是回文数",a);
getchar();
	return 0;
}