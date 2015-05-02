//8、猴子吃桃问题。猴子第一天摘下若干个桃子，当即吃了一半， 还不过瘾，又多吃了一个。第二天早上又将剩下的桃子吃掉 一半，又多吃一个。以后每天早上都吃了前一天剩下的一半 零一个。到第10天早上想再吃时，见只剩下一个桃子了。求 第一天共摘多少桃子.
#include<stdio.h>
int fun(int n)
{
	if(n==1)return 1;
	return (fun(n-1)+1)*2;
}
int main()
{
	printf("%d",fun(10));
	getchar();
	return 0;
}