//103、请编程实现从键盘输入字符串，并将其保存到文件中去。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char c;
	fp=fopen("temp.txt","w");
	while((c=getchar())!='\n')
		fputc(c,fp);
	fclose(fp);
	getchar();
	return 0;
}
