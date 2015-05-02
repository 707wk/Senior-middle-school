//25、请将一个数插入到已排好序的数列中，使其仍然为原序。
#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,6,7,8,9,10},n,i,j;
	scanf("%d",&n);
	for(i=0;a[i]<n&&i<9;i++);
	for(j=9;j>i;j--)a[j]=a[j-1];
	a[i]=n;
	for(i=0;i<10;printf("%3d",a[i++]));
	getchar();
	getchar();
	return 0;
}