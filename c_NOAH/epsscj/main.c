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
    if(ans==c||ans==c+32)printf("\n����ȷ!\n");
    else 
    {
      printf("\n�𰸴���,��ȷ����:%c\n",c);
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
  printf("˵    ��:\n");
  printf("���� q ���˳�\n�������:�����⼯���Ϊ�ı��ĵ��滻error�ļ�����\n�������Ŀ�ռ���ec�ļ�\n   made by GT-soft studio\n��ҳ:http://gtsoft.cwsurf.de/\n��ȷ��������");
}
int main()
{
  system("clear");
  abo();
  while(getch()!='\r');
  opt();
}
