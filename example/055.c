//55�������������������д��Сд��Сд���д���㷨��
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