//24����ѡ�񷨡��ȽϷ���ð�ݷ�����ʮ����������
#include<stdio.h>
void xuan()
{
	int a[10]={4,6,7,2,3,8,9,1,3,2},i,j,t,tmp;
	for(i=0;i<9;i++)
	{
		t=i;
		for(j=i+1;j<10;j++)
			if(a[t]>a[j])t=j;
		tmp=a[t];
		a[t]=a[i];
		a[i]=tmp;
	}
	printf("ѡ������:");
	for(i=0;i<10;printf("%3d",a[i++]));
}
void bi()
{
	int a[10]={4,6,7,2,3,8,9,1,3,2},i,j,tmp;
	for(i=0;i<9;i++)
		for(j=i+1;j<10;j++)
			if(a[i]>a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	printf("\n�ȽϷ�����:");
	for(i=0;i<10;printf("%3d",a[i++]));
}
void mao()
{
	int a[10]={4,6,7,2,3,8,9,1,3,2},i,j,tmp;
	for(i=0;i<9;i++)
		for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
	printf("\nð�ݷ�����:");
	for(i=0;i<10;printf("%3d",a[i++]));
}
int main()
{

	xuan();
	bi();
	mao();
	getchar();
	return 0;
}