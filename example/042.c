//42�����ñȽϷ���ʮ���ַ�������
#include<stdio.h>
int main()
{
	int a[10]={4,6,7,8,3,45,35,43,2,4},i,j,tmp;
	for(i=0;i<9;i++)
		for(j=i+1;j<10;j++)
			if(a[i]>a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	for(i=0;i<10;printf("%3d",a[i++]));
	getchar();
	return 0;
}