//99、用calloc函数动态的创建一个整型数组，并将其内容输出。
#include<stdio.h>
#include<malloc.h>
int main()
{
	int *head,*p;
	head=(int *)calloc(10,sizeof(int));
	for(p=head;p<head+10;p++)*p=p-head+1;
	for(p=head;p<head+10;p++)printf("%3d",*p);
	getchar();
	return 0;
}
