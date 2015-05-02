//41、用折半法查找指定字符串中的字符。
#include<stdio.h>
int main()
{
	char a[]="abcdefghijkmn",c;
	int left=0,right=strlen(a)-1,mid=(left+right)/2;
	scanf("%c",&c);
	for(;left<right;)
	{	
		if(a[mid]==c)break;
		if(a[mid]>c)right=mid-1;
		else left=mid+1;
		mid=(left+right)/2;
	}
	if(a[mid]==c)printf("it is %d",mid+1);
	else printf("not find!");
	getchar();
	getchar();
	return 0;
}