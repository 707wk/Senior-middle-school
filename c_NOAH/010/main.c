#include<stdio.h>
#include<stdlib.h>
#include"option.h"
void Monoidal()  //����ѡ��
{
  FILE *fp1;
  char d,answer,e,mo,question;
  long mplac;
  getchar();
  system("cls");
  fp1=fopen("Mono","r");
  printf("�����ϴν�����? y/n\n");
  scanf("%c",&mo);
  system("cls");
  if(mo=='y'||mo=='Y')fseek(fp1,option('b','r',"a",1),SEEK_SET);
  else fseek(fp1,0,SEEK_SET);
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
      printf("\n������ѡ��:");
      scanf("%c",&answer);
      if(answer=='q')
      {
        getchar();
        return;
      }
      if(answer=='\n')
      {
        while(answer=='\n')
        {
          printf("�������������������𰸣�");
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
     /* printf("�Ƿ������ y/n\n");
      scanf("%c",&question);
      if(!(question=='y'||question=='Y'))
      {
        printf("\n��ȷ�ϼ��˳�\n");
        break;
      }
      getchar();
      mplac=ftell(fp1);
      Mploff(mplac); */
      option('b','w',"a",ftell(fp1));
      getchar();
      system("cls");
    }
    else d=fgetc(fp1);
  }
  fclose(fp1);
  getchar();
  printf("it is end...\n");
  getchar();
  system("cls");
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
}
void Reading()   //�������
{
  FILE *fp2;
  long replac;
  char e,explain,re,question;
  getchar();
  system("cls");
  fp2=fopen("Read","r");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&re);
  if(re=='y'||re=='Y') fseek(fp2,reon(),SEEK_SET);
  else  fseek(fp2,0,SEEK_SET);
  system("cls");
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
      system("cls");
    }
    else
    {
      e=fgetc(fp2);
    }
  }
  getchar();
  getchar();
  fclose(fp2);
  printf("it is end...\n");
  system("sleep 1s && cls");
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
  system("cls");
  getchar();
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&answer);
  getchar();
  system("cls");
  if(answer=='y'||answer=='Y')fseek(fp,Coon(),SEEK_SET);
  else  fseek(fp,0,SEEK_SET);
  word=fgetc(fp);
  while(word!=EOF)
  {
    system("cls");
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
  getchar();
  printf("it is end...\n");
  system("sleep 1s && cls");
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
  system("cls");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&b);
  system("cls");
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
      system("cls");
    }
    else
    {
      a=fgetc(fp);
    }
  }
  fclose(fp);
  getchar();
  getchar();
  printf("it is end...\n");
  system("sleep 1s && cls");
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
  system("cls");
  fp1=fopen("Rc","r");
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&mo);
  system("cls");
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
      system("cls");
    }
  }
  fclose(fp1);
  getchar();
  getchar();
  printf("it is end...\n");
  system("sleep 1s && cls");
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
  system("cls");
  fp3=fopen("Word","r");
  getchar();
  printf("�����ϴν����� ? y/n\n");
  scanf("%c",&est);
  if(est=='y'||est=='Y')fseek(fp3,wordon(),SEEK_SET);
  else  fseek(fp3,0,SEEK_SET);
  system("cls");
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
      system("cls");
    }
    else w=fgetc(fp3);
  }
  fclose(fp3);
  getchar();
  getchar();
  printf("it is end...\n");
  system("sleep 1s && cls");
}
void about()
{
  
  system("cls");
  printf("  ��������      GT-soft ������ ����\n            ��ҳ: http://gtsoft.cwsurf.de/\n           ��������: 799382072@qq.com\n                     1174843091@qq.com\n");
  getchar();
  getchar();
}
void password()
{
  int i=0,n=0;
  char a[200]="a",b;
  getchar();
  system("cls");
  printf("�����������룺");
  while((b=getch())!='\r')
  {
    if(b!=127)
    {
      printf("*");
      a[i]=b;
      i++;
    }
    else if(i>0)
    {
      i--;
      system("cls");
      printf("�����������룺");
      for(n=0;n<i;n++)printf("*");
    }
    a[i]='\0';
  }
  system("cls");
  option('a','w',a,1);
  printf("�����޸ĳɹ���");
  getchar();
}
void opt()
{
  char b;
  do
  {
    system("cls");
    printf("             ģ��:\n   a.����ѡ�� b.������� c.�Ķ����   \n   d.д������ e.�������� f.����Ĭд\n   g.����     h.�������� i.�˳�\n   ������ѡ��: ");
    scanf("%c",&b);
    while(!(b>='a'&&b<='i'))
    {
      system("cls");
      printf("             ģ��:\n   a.����ѡ�� b.������� c.�Ķ����   \n   d.д������ e.�������� f.����Ĭд\n   g.����     h.�������� i.�˳�\n\n");
      printf("��������������ѡ�� : ");
      scanf("%c",&b);
    }
    switch(b){
    case 'a':Monoidal();break;
    case 'b':Reading();break;
    case 'c':recom();break;
    case 'd':tran();break;
    case 'e':cont();break;
    case 'f':Word();break;
    case 'g':about();break;
    case 'h':password();break;
    }
  }while(b!='i');
  system("killall embeddedkonsole");
}
int main()
{
  int i=0,n=0;
  char a[100]="a",b,c[100]="a";
  //chdir("/mnt/mmc/system/ep");
  //system("cls \n echo '\n\n\n                GT-soft studio \n               ��Ȩ���� 1998-2014' \n sleep 3s \n cls");
  option('a','r',c,1);
  system("cls");
  printf("  ����������: ");
  while((b=getch())!='\r')
  {
    if(b!=127)
    {
      printf("*");
      a[i]=b;
      i++;
    }
    else 
    {
      if(i>0)i--;
      system("cls");
      printf("  ����������: ");
      for(n=0;n<i;n++)printf("*");
    }
  }
  a[i]='\0';
  while(strcmp(a,c)!=0)
  {
    system("cls");
    printf("  �������,�������������� : ");
    i=0;
    while((b=getch())!='\r')
    {
      if(b!=127)
      {
        printf("*");
        a[i]=b;
        i++;
      }
      else
      {
        if(i>0)i--;
        system("cls");
        printf("  �������,�������������� : ");
        for(n=0;n<i;n++)printf("*");
      }
    }
    a[i]='\0';
  }
  //text:
  opt();
}
