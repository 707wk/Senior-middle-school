/**************************************
 *FILE    :main.c
 *PROJECT :eps
 *AUTHOR  :707wk
 *CREATED :5/19/2013
 *TEXT:Error Practice System 正式版 V2.0
***************************************/
//#include"getch.h"
#include"option.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void err()
{
  FILE *in,*out;
  if((in=fopen("tmp","r"))==NULL)
  {
    printf("error");
    return ;
  }
  if((out=fopen("ec","a"))==NULL)
  {
    printf("error");
    return ;
  }
  while(!feof(in))fputc(fgetc(in),out);
  fclose(in);
  fclose(out);
  fopen("tmp","w");
}
void ptf()
{
  if(fopen("tmp","w")==NULL)printf("tmp can not be null");
}
void pt(char c)
{
  FILE *fp;
  if((fp=fopen("tmp","a"))==NULL)
  {
    printf("tmp can not open");
    return ;
  }
  fputc(c,fp);
  fclose(fp);
}
void ud(FILE *fp)
{
  //system("cls");
  int s=0;
  char c;
  printf("请输入题号:");
  c=getch(); 
  while(c!='\r'&&c!=27)
  {
    if(c>='0'&&c<='9')
    {
      printf("%c",c);
      s=s*10+c-'0';
    }
    c=getch();
  }
  while(c==27)
  {
    system("cls");s=0;
    printf("请输入题号:");
    c=getch();
    while(c!='\r'&&c!=27)
    {
      if(c>='0'&&c<='9')
      {
        printf("%c",c);
        s=s*10+c-'0';
      }
      c=getch();
    }
  }
  rewind(fp);
  if(s==1||s==0)return ;
  while(s>1)
  {
    if((c=fgetc(fp))=='^')s--;
    if(c==EOF&&s>1)
    {
      system("cls");
      printf("error!数值超出范围\n按确定键返回第一题");
      while(getch()!='\r');
      fseek(fp,0,SEEK_SET);
      return ;
    }
  }
  fgetc(fp);
  fgetc(fp);
  fgetc(fp);
}
void opt()      
{
  FILE *fp;
  char ans,c,tmp;
  system("cls");
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
  system("cls");
  while(c!=EOF)
  {
    system("cls");
    while(c!='^')
    {
      putchar(c);
      pt(c);
      c=fgetc(fp);
    }
    pt(c);
    c=fgetc(fp);
    pt(c);
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
    if(ans=='u')
    {
      ud(fp);
      ptf();
      c='\b';
      ans='\b';
      continue;
    }
    if(ans==c||ans==c+32)printf("\n答案正确!\n");
    else 
    {
      printf("\n答案错误,正确答案是:%c\n",c);
      err();
      ptf();
    }
    ptf();
    while(getch()!='\r');
    pt(fgetc(fp));
    pt(fgetc(fp));
    option('w',ftell(fp));
    c=fgetc(fp);
    if(c==EOF)
    {  
      fseek(fp,0,SEEK_SET);
      c=fgetc(fp);
      system("cls");
      printf("题目已做完,按确定键返回第一题");
      while(getch()!='\r');
    }
    system("cls");
  }
  fclose(fp);
}
void opte()    
{
  FILE *fp;
  char ans,c,tmp;
  system("cls");
  fp=fopen("ec","r");
  c=fgetc(fp);
  system("cls");
  ptf();
  while(c!=EOF)
  {
    system("cls");
    while(c!='^')
    {
      putchar(c);
      c=fgetc(fp);
    }
    c=fgetc(fp);
    printf("请输入答案: ");
    tmp=getch();
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
    if(ans=='u')
    {
      ud(fp);
      c='\b';
      ans='\b';
      continue;
    }
    if(ans==c||ans==c+32)printf("\n答案正确!\n");
    else printf("\n答案错误,正确答案是:%c\n",c);
    while(getch()!='\r');
    fgetc(fp);
    fgetc(fp);
    c=fgetc(fp);
    if(c==EOF)
    {  
      system("cls");
      printf("题目已做完,是否清空错题？ y/n  ");
      while((tmp=getch())=='\r');
      while(tmp!='\r')
      {
        if(tmp=='y'||tmp=='Y'||tmp=='n'||tmp=='N')
        {
          c=tmp;
          printf("\b%c",c);
          tmp=getch();
        }
      }
      if(c=='y'||c=='Y')
      {
        fopen("ec","w");
        system("cls");
        printf("错题已清空！\n");
        return ;
      }
      else return ;
      getch();
    }
    c=fgetc(fp);
    system("cls");
  }
  fclose(fp);
}
void abo()
{
  printf("说    明:\n");
  printf("输入 q 退出\n输入 u 跳题\n导入错题:将错题集另存为文本文档替换error文件即可\n做错的题目收集在ec文件\n   made by GT-soft studio\n主页:http://gtsoft.cwsurf.de/\n按确定键继续");
}
int main()
{
  char tmp,c;
  system("cls");
  abo();
  while(getch()!='\r');
  for(;;)
  {
    system("cls");
    printf("选项：\na:正常练习\nb:错题练习\nq:退出\n选择： ");
    tmp=getch();
    while(tmp=='\r')tmp=getch();
    while(tmp!='\r')
    {
      if(tmp>='a'&&tmp<='z')
      {
        c=tmp;
        printf("\b%c",tmp); 
      }
      tmp=getch();  
    }
    switch(c)
    {
      case 'a':opt();break;
      case 'b':opte();break;
      case 'q':exit(0);
   }
   system("cls");
  }
}
