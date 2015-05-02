//15、请编程求一个数的分解质因数（例如：90=2*3*3*5）
#include<stdio.h>
int main()
{
	int n,tmp;
	scanf("%d",&n);
	printf("%3d = ",n);
	while(n>1)
	{
		for(tmp=2;tmp<=n;tmp++)
			if(n%tmp==0){printf("%d*",tmp);n=n/tmp;break;}
	}
	printf("\b \b");
	getchar();
	getchar();
	return 0;
}