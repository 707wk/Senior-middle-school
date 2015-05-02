//55、用条件编译命令求大写变小写，小写变大写的算法。
#include<stdio.h>
#define d
int main()
{
	char a='a';
	#ifdef d
		printf("%c",a-=32);
	#else
		printf("%d",a);
	#endif
	getchar();
	return 0;
}