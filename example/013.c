//13������һ�����жϸ����Ƿ�Ϊ�������������磺1221����һ����������
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
if(fun(a))printf("%s�ǻ�����",a);
else printf("%s���ǻ�����",a);
getchar();
	return 0;
}