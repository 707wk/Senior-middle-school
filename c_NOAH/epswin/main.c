/**************************************
 *FILE    :main.c
 *PROJECT :eps
 *AUTHOR  :707wk
 *CREATED :5/19/2013
 *TEXT:Error Practice System ��ʽ�� V2.0
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
  printf("���������:");
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
    printf("���������:");
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
      printf("error!��ֵ������Χ\n��ȷ�������ص�һ��");
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
  printf("�Ƿ�����ϴ���ϰ����? y/n  ");
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
    printf("�������: ");
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
    if(ans==c||ans==c+32)printf("\n����ȷ!\n");
    else 
    {
      printf("\n�𰸴���,��ȷ����:%c\n",c);
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
      printf("��Ŀ������,��ȷ�������ص�һ��");
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
    printf("�������: ");
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
    if(ans==c||ans==c+32)printf("\n����ȷ!\n");
    else printf("\n�𰸴���,��ȷ����:%c\n",c);
    while(getch()!='\r');
    fgetc(fp);
    fgetc(fp);
    c=fgetc(fp);
    if(c==EOF)
    {  
      system("cls");
      printf("��Ŀ������,�Ƿ���մ��⣿ y/n  ");
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
        printf("��������գ�\n");
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
  printf("˵    ��:\n");
  printf("���� q �˳�\n���� u ����\n�������:�����⼯���Ϊ�ı��ĵ��滻error�ļ�����\n�������Ŀ�ռ���ec�ļ�\n   made by GT-soft studio\n��ҳ:http://gtsoft.cwsurf.de/\n��ȷ��������");
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
    printf("ѡ�\na:������ϰ\nb:������ϰ\nq:�˳�\nѡ�� ");
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
