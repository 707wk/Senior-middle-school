//36�����ʵ�ֽ����ź�����ַ�����a����b�����е�Ԫ�ذ�a�����еĹ��ɲ��뵽a��
#include<stdio.h>
void fun(char *a,char *b)
{
	char *p=a,*q,tmp;
	strcat(a,b);
	for(;*(p+1);p++)
		for(q=p+1;*q;q++)
			if(*p>*q)
			{
				tmp=*p;
				*p=*q;
				*q=tmp;
			}
}
int main()
{
	char a[100]="13579",b[]="82460";
	fun(a,b);
	puts(a);
	getchar();
	return 0;
}