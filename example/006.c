//6、警察抓了四个小偷,问第一个说我不是小偷,问第二个说 第三个是小偷,问第三个说第四个是小偷,问第四个说有 人冤枉我了,其中三个说真话一人说假话,试编程求哪一 个是小偷?(用两种方法）
#include<stdio.h>
int main()
{
	char x;
	for(x='a';x<='d';x++)
		if(((x!='a')+(x=='c')+(x=='d')+(x!='d'))==3)break;
	printf("%c",x);
	getchar();
	return 0;
}