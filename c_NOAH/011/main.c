#include<stdio.h>
#include<stdlib.h>
#include"getch.h"
long Mplon()
{
  FILE *fp;
  long sum=0;
  char num;
  fp=fopen("Mpl","r");
  num=fgetc(fp);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fp);
  }
  fclose(fp);
  return sum;
}
void Mploff(long mploff)
{
  FILE *fp11;
  fp11=fopen("Mpl","w");
  fprintf(fp11,"%ld",mploff);
  fclose(fp11);
}
void Monoidal()  //单项选择
{
  FILE *fp1;
  char d,answer,e,mo,question;
  long mplac;
  void option();
  getchar();
  system("clear");
  fp1=fopen("Mono","r");
  printf("继续上次进度吗? y/n\n");
  scanf("%c",&mo);
  system("clear");
  if(mo=='y'||mo=='Y')fseek(fp1,Mplon(),SEEK_SET);
  else  fseek(fp1,0,SEEK_SET);
  d=fgetc(fp1);
  getchar();
  while(d!=EOF)
  {
    if(d=='{')
    {
      d=fgetc(fp1);
      do
      {
      putchar(d);
      d=fgetc(fp1);
      }while(d!='}');
      printf("\n请输入选项:");
      scanf("%c",&answer);
      if(answer=='\n')
      {
        while(answer=='\n')
        {
          printf("错误参数！请重新输入答案：");
          scanf("%c",&answer);
        }
      }
      do
      {
        d=fgetc(fp1);
      }while(d!='<');
      e=fgetc(fp1);
      if(e==answer)printf("答案正确!\n你的答案是 %c\n",e);
      else printf("答案错误！\n正确答案是 %c\n",e);
      if(answer!='\n')
      {
        if(getchar()!='\n')
        {
          while(answer!='\n')
          {
            scanf("%c",&answer);
          }
        }
      }
      printf("是否继续？ y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      getchar();
      mplac=ftell(fp1);
      Mploff(mplac);
    }
    else
    {
      d=fgetc(fp1);
      system("clear");
    }
  }
  fclose(fp1);
  getchar();
  printf("it is end...");
  getchar();
  option();
}
long reon()
{
  FILE *fpe;
  long sum=0;
  char num;
  fpe=fopen("Rpl","r");
  num=fgetc(fpe);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fpe);
  }
  fclose(fpe);
  return sum;
}
void reoff(long reoff)
{
  FILE *fp12;
  fp12=fopen("Rpl","w");
  fprintf(fp12,"%ld",reoff);
  fclose(fp12);
}
void decide(FILE *fp2)
{
  char a[40],enswer,key,*key1;
  scanf("%s",a);
  getch();
  while(strcmp(a,"")==0)
   {
     printf("错误参数！请重新输入答案：");
     scanf("%s",a);
     getch();
   }
  key=fgetc(fp2);
  key1=a;
  while(key!='>')
  {
    if((*key1)!=key)printf("X");
    else printf(" ");
    key=fgetc(fp2);
    key1++;
  }
}
void Reading()   //完形填空
{
  FILE *fp2;
  void option();
  long replac;
  char e,explain,re,question;
  getchar();
  system("clear");
  fp2=fopen("Read","r");
  printf("继续上次进度吗 ? y/n\n");
  scanf("%c",&re);
  if(re=='y'||re=='Y')fseek(fp2,reon(),SEEK_SET);
  else  fseek(fp2,0,SEEK_SET);
  system("clear");
  e=fgetc(fp2);
  getchar();
  while(e!=EOF)
  {
    if(e=='{')
    {
      e=fgetc(fp2);
      do
      {
        putchar(e);
        e=fgetc(fp2);
      }while(e!='}');
      e=fgetc(fp2);
      printf("请输入答案:\n");
      while(e!='<')
      {
        e=fgetc(fp2);
      }
      decide(fp2);
      printf("\n需要讲解吗? y/n ");
      scanf("%c",&explain);
      if(explain=='y')
      {
        do
        {
          e=fgetc(fp2);
        }while(e!='(');
        e=fgetc(fp2);
        do
        {
          putchar(e);
          e=fgetc(fp2);
        }while(e!=')');
      }
      replac=ftell(fp2);
      reoff(replac);
      getchar();
      printf("是否继续？y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      getchar();
      system("clear");
    }
    else
    {
      e=fgetc(fp2);
    }
  }
  printf("it is end...");
  getchar();
  option();
}
long Coon()
{
  FILE *fpe;
  long sum=0;
  char num;
  fpe=fopen("Copl","r");
  num=fgetc(fpe);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fpe);
  }
  fclose(fpe);
  return sum;
}
void cooff(long cooff)
{
  FILE *fp12;
  fp12=fopen("Copl","w");
  fprintf(fp12,"%ld",cooff);
  fclose(fp12);
}
void cojudge(FILE *fp)
{
  char a[40],b[40],com;
  int n=0;
  printf("请输入答案:\n");
  scanf("%s",a);
 
getch();
  while(strcmp(a,"")==0)
   {
     printf("错误参数！请重新输入答案：");
     scanf("%s",a);
    
getch();
   }
  com=fgetc(fp);
  while(com!='>')
  {
    b[n]=com;
    com=fgetc(fp);
    n++;
  }
  if(strcmp(a,b)==0)printf("答案正确！");
  else
  {
    printf("答案错误！\n正确答案是：");
    puts(b);
  }
}
void recom()    //阅读理解
{
  FILE *fp;
  char word,answer,question;
  long com;
  void option();
  fp=fopen("Co","r");
  system("clear");
  getchar();
  printf("继续上次进度吗 ? y/n\n");
  scanf("%c",&answer);
  getchar();
  system("clear");
  if(answer=='y'||answer=='Y')fseek(fp,Coon(),SEEK_SET);
  else  fseek(fp,0,SEEK_SET);
  word=fgetc(fp);
  while(word!=EOF)
  {
    system("clear");
    if(word=='{')
    {
      word=fgetc(fp);
      while(word!='}')
      {
        putchar(word);
        word=fgetc(fp);
      }
      while(word!='<')
      {
        word=fgetc(fp);
      }
      cojudge(fp);
      printf("是否继续？y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      com=ftell(fp);
      cooff(com);
      getchar();
    }
    else
    {
      word=fgetc(fp);
    }
  }
  getchar();
  option();
}
long inton()
{
  FILE *fpe;
  long sum=0;
  char num;
  fpe=fopen("Intpl","r");
  num=fgetc(fpe);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fpe);
  }
  fclose(fpe);
  return sum;
}
void intoff(long intoff)
{
  FILE *fp12;
  fp12=fopen("Intpl","w");
  fprintf(fp12,"%ld",intoff);
  fclose(fp12);
}
void inte(FILE *fp)
{
  char a[200],b[200]={'\0'},c;
  int n=0;
  scanf("%s",a);
 
getch();
  while(strcmp(a,"")==0)
   {
     printf("错误参数！请重新输入答案：");
     scanf("%s",a);
    
getch();
   }
  c=fgetc(fp);
  while(c!='>')
  {
    b[n]=c;
    c=fgetc(fp);
    n++;
  }
  if(strcmp(a,b)==0)printf("翻译正确！");
  else
  {
    printf("\n翻译错误！\n正确翻译是：");
    puts(b);
  }
}
void tran()    //写作翻译(int)
{
  FILE *fp;
  void option();
  char a,b,question;
  long intp;
  getchar();
  fp=fopen("Int","r");
  system("clear");
  printf("继续上次进度吗 ? y/n\n");
  scanf("%c",&b);
  system("clear");
  if(b=='y'||b=='Y')fseek(fp,inton(),SEEK_SET);
  else  fseek(fp,0,SEEK_SET);
  a=fgetc(fp);
  getchar();
  while(a!=EOF)
  {
    if(a=='{')
    {
      a=fgetc(fp);
      while(a!='}')
      {
        putchar(a);
        a=fgetc(fp);
      }
      while(a!='<')
      {
        a=fgetc(fp);
      }
      printf("\n请输入翻译：\n");
      inte(fp);
      intp=ftell(fp);
      intoff(intp);
      printf("是否继续？y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      getchar();
      system("clear");
    }
    else
    {
      a=fgetc(fp);
    }
  }
  printf("it is end...");
  getchar();
  option();
}
long Rcon()
{
  FILE *fp;
  long sum=0;
  char num;
  fp=fopen("Rcpl","r");
  num=fgetc(fp);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fp);
  }
  fclose(fp);
  return sum;
}
void Rcoff(long rcoff)
{
  FILE *fp11;
  fp11=fopen("Rcpl","w");
  fprintf(fp11,"%ld",rcoff);
  fclose(fp11);
}
void cont()  //交际用语(rc)
{
  FILE *fp1;
  char d,answer,e,mo,question;
  long rcpl;
  void option();
  getchar();
  system("clear");
  fp1=fopen("Rc","r");
  printf("继续上次进度吗 ? y/n\n");
  scanf("%c",&mo);
  system("clear");
  if(mo=='y'||mo=='Y')fseek(fp1,Rcon(),SEEK_SET);
  else  fseek(fp1,0,SEEK_SET);
  d=fgetc(fp1);
  getchar();
  while(d!=EOF)
  {
    if(d=='{')
    {
      d=fgetc(fp1);
      do
      {
      putchar(d);
      d=fgetc(fp1);
      }while(d!='}');
      printf("\n请输入选项:");
      scanf("%c",&answer);
      if(answer=='\n')
      {
        while(answer=='\n')
        {
          printf("错误参数！请重新输入答案：");
          scanf("%c",&answer);
        }
      }
      if(answer=='q')
      {
        printf("\n按确认键退出\n");
        break;
      }
      do
      {
        d=fgetc(fp1);
      }while(d!='<');
      e=fgetc(fp1);
      if(e==answer)printf("答案正确!\n你的答案是 %c\n",e);
      else printf("答案错误！\n正确答案是 %c\n",e);
      if(getchar()!='\n')
      {
        while(answer!='\n')
        {
          scanf("%c",&answer);
        }
      }
      printf("是否继续？y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      rcpl=ftell(fp1);
      Rcoff(rcpl);
      getchar();
    }
    else
    {
      d=fgetc(fp1);
      system("clear");
    }
  }
  fclose(fp1);
  getchar();
  printf("it is end...");
  getchar();
  option();
}
void judge(FILE *fp3)
{
  FILE *fpb;
  char b[100],c[100]={'\0'},word;
  int i=0;
  /*gets(b);
*/
scanf("%s",b);getch();
  while(strcmp(b,"")==0)
   {
     printf("错误参数！请重新输入答案：");
     /*gets(b);*/
  }
  if(strcmp(b,c)==0)printf("答案正确！");
  else
  {
    printf("答案错误！\n正确答案是：");
    puts(c);
  }
}
long wordon()
{
  FILE *fp;
  long sum=0;
  char num;
  fp=fopen("Wpl","r");
  num=fgetc(fp);
  while(num!=EOF)
  {
    sum=sum*10+num-'0';
    num=fgetc(fp);
  }
  fclose(fp);
  return sum;
}
void wordoff(long woff)
{
  FILE *fp12;
  fp12=fopen("Wpl","w");
  fprintf(fp12,"%ld",woff);
  fclose(fp12);
}
void Word()      //单词
{
  FILE *fp3;
  char w,est,question;
  long west;
  void option();
  system("clear");
  fp3=fopen("Word","r");
  getchar();
  printf("继续上次进度吗 ? y/n\n");
  scanf("%c",&est);
  if(est=='y'||est=='Y')fseek(fp3,wordon(),SEEK_SET);
  else  fseek(fp3,0,SEEK_SET);
  system("clear");
  w=fgetc(fp3);
  getchar();
  while(w!=EOF)
  {
    if(w=='{')
    {
      w=fgetc(fp3);
      while(w!='}')
      {
        putchar(w);
        w=fgetc(fp3);
      }
      printf("\n");
      while(w!='<')
      {
        w=fgetc(fp3);
      }
      judge(fp3);
      printf("是否继续？y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n按确认键退出\n");
        break;
      }
      west=ftell(fp3);
      wordoff(west);
      getchar();
      system("clear");
    }
    else w=fgetc(fp3);
  }
  printf("it is end...");
  getchar();
  option();
}
void about()
{
  void option();
  system("clear");
  printf("  本程序由      GT-soft 工作室 制作\n            主页: http://gtsoft.cwsurf.de/\n           电子邮箱: 799382072@qq.com\n                     1174843091@qq.com\n");
  getchar();
  getchar();
  option();
}
void password()
{
  FILE *fp;
  void option();
  int i=0,n=0;
  char a[200]={0},b;
  fp=fopen("mima","w");
  getchar();
  system("clear");
  printf("请输入新密码：");
  while((b=getch())!='\r')
  {

    if(b!=127)
    {
      printf("*");
      a[i]=b-1;
      i++;
    }
    else if(i>0)
    {
      i--;
      system("clear");
      printf("请输入新密码：");
      for(n=0;n<i;n++)printf("*");
    }
  }
  system("clear");
  fputs(a,fp);
  printf("密码修改成功！");
  fclose(fp);
  getchar();
  option();
}
void option()
{
  char b;
  system("clear");
  printf("             模块:\n   a.单项选择 b.完形填空 c.阅读理解   \n   d.写作翻译 e.交际用语 f.单词默写\n   g.关于     h.更改密码 i.退出\n   请输入选项: ");
  scanf("%c",&b);
  while(!(b>='a'&&b<='i'))
  {
    system("clear");
    printf("             模块:\n   a.单项选择 b.完形填空 c.阅读理解   \n   d.写作翻译 e.交际用语 f.单词默写\n   g.关于     h.更改密码 i.退出\n\n");
    printf("错误！请重新输入选项 : ");
    scanf("%c",&b);
  }
  if(b=='a')Monoidal();
  else if(b=='b')Reading();
  else if(b=='c')recom();
  else if(b=='d')tran();
  else if(b=='e')cont();
  else if(b=='f')Word();
  else if(b=='g')about();
  else if(b=='h')password();
}
int main()
{
  option();
}
