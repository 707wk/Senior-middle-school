//70、用指针法实现数组中首元素存与最小者交换，尾元素与最大者交换。
#include<stdio.h>
int main()
{
	int a[10]={2,3,4,5,6,7,8,9,10,1},*head,*p,*q,temp;
	for(head=p=q=a;head<a+10;head++)
	{
		if(*head>*p)p=head;
		if(*head<*q)q=head;
	}
	temp=*q;
	*q=*a;
	*a=temp;
	temp=*p;
	*p=*(a+9);
	*(a+9)=temp;
	for(head=a;head<a+10;head++)printf("%3d",*head);
	getchar();
	return 0;
}
