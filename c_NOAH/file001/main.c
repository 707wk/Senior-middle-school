/**************************************
 *FILE    :main.c
 *PROJECT :file001
 *AUTHOR  :707wk
 *CREATED :4/21/2013
***************************************/
#include<stdio.h>
#include<stdlib.h>
struct opt
{
char name[100];
char number[100];
char address[100];
};
/*怎样修改文件的某一部分数据*/
int main(int argc, char *argv[])
{
FILE *fp;
struct opt option;
char c;
fp=fopen("tmp","r");
while((c=fgetc(fp))!=EOF)
{
while(c!="\n")
{
*option.name=c;
c=fgetc(fp);
option.name++;
} 
while((c=fgetc(fp))!="\n")
{
*option.number=c;
option.number++;
}
}
puts(option.name);
puts(option.number);
fclose(fp);
}
