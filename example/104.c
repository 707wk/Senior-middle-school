//104、请编程实现将A.txt里面的内容复制到B.txt中去。
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp,*fq;
char c;
fp=fopen("a.txt","r");
fq=fopen("b.txt","w");
while(!feof(fp))
{
fprintf(fq,"%c",c);
}
fclose(fp);
fclose(fq);
getchar();
return 0;
}
