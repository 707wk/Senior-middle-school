#include<stdio.h>
#include<stdlib.h>
#include"getch.h"
int queren(char a[])
{
  FILE *fp;
  char c;
  fp=fopen("mima","r");
  c=fgetc(fp);
  while((c!=EOF)||(*a!='\0'))
  {
    if((*a)!=c)return 1;
    a++;
    c=fgetc(fp);
  }
  fclose(fp);
  return 0;
}
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
void Monoidal()  //����ѡ��
{
  FILE *fp1;
  char d,answer,e,mo,question;
  long mplac;
  getchar();
  system("reset");
  fp1=fopen("Mono","r");
  printf("�����ϴν�����? y/n\n");
  scanf("%c",&mo);
  system("reset");
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
      printf("\n");
      printf("\n������ѡ��:\n");
      scanf("%c",&answer);
      if(answer=='\n')
      {
        while(answer=='\n')
        {
          printf("�������������������𰸣�\n");
          scanf("%c",&answer);
        }
      }
      do
      {
        d=fgetc(fp1);
      }while(d!='<');
      e=fgetc(fp1);
      if(e==answer)printf("����ȷ!\n��Ĵ��� %c\n",e);
      else printf("�𰸴���\n��ȷ���� %c\n",e);
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
      printf("�Ƿ������ y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      getchar();
      mplac=ftell(fp1);
      Mploff(mplac);
    }
    else
    {
      d=fgetc(fp1);
      system("reset");
    }
  }
  fclose(fp1);
  getchar();
  printf("it is end... \n\n\n ");
  getchar();
  system("reset");
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
     printf("�������������������𰸣�");
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
void prin(FILE *fp)
{
  char e;
  e=fgetc(fp);
  do
  {
    putchar(e);
    e=fgetc(fp);
  }while(e!='}');
  printf("\n");
}
void Reading()   //�������
{
  FILE *fp2;
  long replac;
  char e,explain,re,question;
  getchar();
  system("reset");
  fp2=fopen("Read","r");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&re);
  if(re=='y'||re=='Y') fseek(fp2,reon(),SEEK_SET);
  else  fseek(fp2,0,SEEK_SET);
  system("reset");
  e=fgetc(fp2);
  getchar();
  while(e!=EOF)
  {
    if(e=='{')
    {
      prin(fp2);
      e=fgetc(fp2);
      printf("�������:\n");
      while(e!='<') e=fgetc(fp2);
      decide(fp2);
      printf("\n��Ҫ������? y/n ");
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
        printf("\n");
      }
      replac=ftell(fp2);
      reoff(replac);
      getchar();
      printf("�Ƿ������y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      getchar();
      system("reset");
    }
    else
    {
      e=fgetc(fp2);
    }
  }
  fclose(fp2);
  printf("it is end... \n\n ");
  system("reset");
  getchar();
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
  printf("�������:\n");
  scanf("%s",a);
  getch();
  while(strcmp(a,"")==0)
   {
     printf("�������������������𰸣�");
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
  if(strcmp(a,b)==0)printf("����ȷ��");
  else
  {
    printf("�𰸴���\n��ȷ���ǣ�");
    puts(b);
  }
}
void recom()    //�Ķ����
{
  FILE *fp;
  char word,answer,question;
  long com;
  fp=fopen("Co","r");
  system("reset");
  getchar();
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&answer);
  getchar();
  system("reset");
  if(answer=='y'||answer=='Y')fseek(fp,Coon(),SEEK_SET);
  else  fseek(fp,0,SEEK_SET);
  word=fgetc(fp);
  while(word!=EOF)
  {
    system("reset");
    if(word=='{')
    {
      word=fgetc(fp);
      while(word!='}')
      {
        putchar(word);
        word=fgetc(fp);
      }
      printf("\n");
      while(word!='<')
      {
        word=fgetc(fp);
      }
      cojudge(fp);
      printf("�Ƿ������y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
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
  fclose(fp);
  getchar();
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
  char a[200]={'\0'},b[200]={'\0'},c;
  int n=0;
  scanf("%s",a);
  getch();
  while(strcmp(a,"")==0)
   {
     printf("�������������������𰸣�");
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
  if(strcmp(a,b)==0)printf("������ȷ��");
  else
  {
    printf("\n�������\n��ȷ�����ǣ�");
    puts(b);
  }
}
void tran()    //д������(int)
{
  FILE *fp; 
  char a,b,question;
  long intp;
  getchar();
  fp=fopen("Int","r");
  system("reset");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&b);
  system("reset");
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
      printf("\n");
      while(a!='<')
      {
        a=fgetc(fp);
      }
      printf("\n�����뷭�룺\n");
      inte(fp);
      intp=ftell(fp);
      intoff(intp);
      printf("�Ƿ������y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      getchar();
      system("reset");
    }
    else
    {
      a=fgetc(fp);
    }
  }
  fclose(fp);
  printf("it is end... \n\n\n ");
  getchar();
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
void cont()  //��������(rc)
{
  FILE *fp1;
  char d,answer,e,mo,question;
  long rcpl; 
  getchar();
  system("reset");
  fp1=fopen("Rc","r");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&mo);
  system("reset");
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
      printf("\n");
      printf("\n������ѡ��:");
      scanf("%c",&answer);
      if(answer=='\n')
      {
        while(answer=='\n')
        {
          printf("�������������������𰸣�");
          scanf("%c",&answer);
        }
      }
      if(answer=='q')
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      do
      {
        d=fgetc(fp1);
      }while(d!='<');
      e=fgetc(fp1);
      if(e==answer)printf("����ȷ!\n��Ĵ��� %c\n",e);
      else printf("�𰸴���\n��ȷ���� %c\n",e);
      if(getchar()!='\n')
      {
        while(answer!='\n')
        {
          scanf("%c",&answer);
        }
      }
      printf("�Ƿ������y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      rcpl=ftell(fp1);
      Rcoff(rcpl);
      getchar();
    }
    else
    {
      d=fgetc(fp1);
      system("reset");
    }
  }
  fclose(fp1);
  getchar();
  printf("it is end... \n\n\n ");
  getchar();
}
void judge(FILE *fp3)
{
  FILE *fpb;
  char b[100]={'\0'},c[100]={'\0'},word;
  int i=0;
  scanf("%s",b);
  getch();
  word=fgetc(fp3);
  while(word!='>')
  {
    c[i]=word;
    word=fgetc(fp3);
    i++;
  }
  b[i]=0;
  while(strcmp(b,"")==0)
   {
     printf("�������������������𰸣�");
     scanf("%s",b);
  }
  if(strcmp(b,c)==0)printf("����ȷ��");
  else
  {
    printf("�𰸴���\n��ȷ���ǣ�");
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
void Word()      //����
{
  FILE *fp3;
  char w,est,question;
  long west;
  system("reset");
  fp3=fopen("Word","r");
  getchar();
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&est);
  if(est=='y'||est=='Y')fseek(fp3,wordon(),SEEK_SET);
  else  fseek(fp3,0,SEEK_SET);
  system("reset");
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
      printf("�Ƿ������y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      west=ftell(fp3);
      wordoff(west);
      getchar();
      system("reset");
    }
    else w=fgetc(fp3);
  }
  fclose(fp3);
  printf("it is end... \n\n\n ");
  getchar();
  system("reset");
}
void about()
{
  
  system("reset");
  printf("  ��������      GT-soft ������ ����\n            ��ҳ: http://gtsoft.cwsurf.de/\n           ��������: 799382072@qq.com\n                     1174843091@qq.com\n");
  getchar();
  getchar();
}
void password()
{
  FILE *fp;
  int i=0,n=0;
  char a[200]={0},b;
  fp=fopen("mima","w");
  getchar();
  system("reset");
  printf("�����������룺");
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
      system("reset");
      printf("�����������룺");
      for(n=0;n<i;n++)printf("*");
    }
  }
  system("reset");
  fputs(a,fp);
  printf("�����޸ĳɹ���");
  fclose(fp);
  getchar();
}
void option()
{
  char b;
  do
  {
    system("reset");
    printf("             ģ��:\n   a.����ѡ�� b.������� c.�Ķ����   \n   d.д������ e.�������� f.����Ĭд\n   g.����     h.�������� i.�˳�\n   ������ѡ��: ");
    scanf("%c",&b);
    while(!(b>='a'&&b<='i'))
    {
      system("reset");
      printf("             ģ��:\n   a.����ѡ�� b.������� c.�Ķ����   \n   d.д������ e.�������� f.����Ĭд\n   g.����     h.�������� i.�˳�\n\n");
      printf("��������������ѡ�� : ");
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
  }while(b!='i');
  system("killall embeddedkonsole");
}
int main()
{
  int i=0,n=0;
  char a[200]={0},b;
  chdir("/mnt/mmc/system/ep");
  system("reset \n echo '\n\n            English-practice ���԰� V-2.0\n                GT-soft studio \n               ��Ȩ���� 1998-2014' \n sleep 2s \n reset");
  printf("  ����������: ");
  while((b=getch())!='\r')
  {
    if(b!=127)
    {
      printf("*");
      a[i]=b-1;
      i++;
    }
    else
    {
      i--;
      system("reset");
      printf("  ����������: ");
      for(n=0;n<i;n++)printf("*");
    }
  }
  while(queren(a))
  {
    system("reset");
    printf("  �������,�������������� : ");
    i=0;
    while((b=getch())!='\r')
    {
      if(b!=127)
      {
        printf("*");
        a[i]=b-1;
        i++;
      }
      else
      {
        i--;
        system("reset");
        printf("  �������,�������������� : ");
        for(n=0;n<i;n++)printf("*");
      }
    }
  }
  option();
}