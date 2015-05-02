/**************************************
 *FILE    :main.c
 *PROJECT :eps
 *AUTHOR  :707wk
 *CREATED :5/19/2013
***************************************/
#include"getch.h"
#include"option.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void err()
{
  FILE *in,*out;
  if((in=fopen("tm","r"))==NULL){printf("error");return ;}
  if((out=fopen("ec","a"))==NULL){printf("error");return ;}
  while(!feof(in))fputc(fgetc(in),out);
  fclose(in);
  fclose(out);
}
void opt()
{
  FILE *fp,*fp1;
  char ans,c,tmp;
  system("clear");
  fp=fopen("error","r");
  printf("是否继续上次练习进度? y/n  ");
  while((tmp=getch())=='\r');
  while(tmp!='\r')
  {
    c=tmp;
    if(c=='y'||c=='Y'||c=='n'||c=='N')printf("\b%c",c);
    tmp=getch();
  }
  if(!(c=='n'||c=='N'))fseek(fp,option('r',1),SEEK_SET);
  c=fgetc(fp);
  system("clear");
  while(c!=EOF)
  {
    system("clear");
    if((fp1=fopen("tm","w+"))==NULL){printf("error");return ;}
    while(c!='^')
    {
      putchar(c);fputc(c,fp1);
      c=fgetc(fp);
    }
    fputc(c,fp1);
    c=fgetc(fp);
    fputc(c,fp1);
    fclose(fp1);
    printf("请输入答案: ");
    while(tmp=='\r')tmp=getch();
    while(tmp!='\r')
    {
      if(tmp>='a'&&tmp<='z'||tmp>='A'&&tmp<='Z')
      {
        ans=tmp;
        printf("\b%c",ans);
      }
      tmp=getch();
    }
    if(ans=='q')return ;
    if(ans==c||ans==c+32)printf("\n答案正确!\n");
    else 
    {
      printf("\n答案错误,正确答案是:%c\n",c);
      err();
    }
    getchar();
    fputc(fgetc(fp),fp1);
    fputc(fgetc(fp),fp1);
    option('w',ftell(fp));
    c=fgetc(fp);
    system("clear");
  }
  fclose(fp);
}
void abo()
{
  printf("说    明:\n");
  printf("输入 q 可退出\n导入错题:将错题集另存为文本文档替换error文件即可\n做错的题目收集在ec文件\n   made by GT-soft studio\n主页:http://gtsoft.cwsurf.de/\n按确定键继续");
}
int main()
{
  system("clear");
  abo();
  while(getch()!='\r');
  opt();
}
