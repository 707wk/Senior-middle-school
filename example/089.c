//89、用指向字符的指针变量将一个数插入到已经排好序的数列中去。
#include<stdio.h>
int main()
{
	int a[6]={1,3,5,7,9},num,i,j;
	scanf("%d",&num);
	for(i=0;a[i]<num&&i<5;i++);
	for(j=5;j>i;j--)a[j]=a[j-1];
	a[i]=num;
	for(i=0;i<6;i++)printf("%3d",a[i]);
	getchar();
	return 0;
}
