//23����������ͳ��10���˵ĵ�Ʊ��
#include<stdio.h>
int main()
{
	int a[10]={0},c;
	for(scanf("%d",&c);c!=-1;scanf("%d",&c))
		if(c>0&&c<=10)a[c-1]++;
	for(c=0;c<10;printf("%3d :%3d\n",c+++1,a[c]));
	getchar();
	getchar();
	return 0;
}