#include<stdio.h>
#include<stdio.h>
void opte()
{
  FILE *fp;
void ud();
  char ans,c,tmp;
  system("clear");
  fp=fopen("ec","r");
  c=fgetc(fp);
  system("clear");
  while(c!=EOF)
  {
    system("clear");
    while(c!='^')
    {
      putchar(fgetc(fp));
    }
    c=fgetc(fp);
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
    if(ans=='u'){ud(fp);c='\b';ans='\b';continue;}
    if(ans==c||ans==c+32)printf("\n����ȷ!\n");
    else 
    {
      printf("\n�𰸴���,��ȷ����:%c\n",c);
    }
    while(getch()!='\r');
    fgetc(fp);
    fgetc(fp);
    c=fgetc(fp);
    if(c==EOF)
    {  
      fseek(fp,0,SEEK_SET);c=fgetc(fp);
      system("clear");
      printf("��Ŀ������,�Ƿ���մ���? y/n  ");
      while(getch()!='\r');
while((tmp=fgetc(fp))!='\r')
{
if(tmp=='y'||tmp=='Y'||tmp=='n'||tmp=='N')printf("\b%c",tmp);
}
if(tmp=='y'||tmp=='Y'){fclose(fp);fopen("ec","w");}
    }
    system("clear");
  }
  fclose(fp);
}
