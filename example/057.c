//57������һ����ά���鲻��ʼ�����������ֵ�Ƿ�Ϊ�������ʵ�顣
#include<stdio.h>
#define M 5
int main()
{
	int a[M][M],i,j;
	for(i=0;i<M;i++,printf("\n"))
		for(j=0;j<M;printf(" %d ",a[i][j++]));
	getchar();
	return 0;
}