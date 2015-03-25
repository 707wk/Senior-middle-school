#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long option(char ch,char rw,char *s)
{
  struct opt{
    char c1[100];
    long c2;
    long c3;
    long c4;
    long c5;
    long c6;
    long c7;  
  };
  char c,nu[100]="abc";
  long i=0;
  FILE *fp;
  struct opt p;
  fp=fopen("option","r");
  if(fp==NULL)
  {
    printf("error!");
    fclose(fp);
    return -1;
  }
  c=fgetc(fp);
  while(c!='\n')
  {
    p.c1[i]=c;
    i++;
    c=fgetc(fp);  
  }
  p.c1[i]='\0';
  c=fgetc(fp);
  p.c2=i=0;
  while(c!='\n')
  {
    nu[i]=c;
    i++; 
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c2=atoi(nu);
  c=fgetc(fp);
  p.c3=i=0;
  while(c!='\n')
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c3=atoi(nu);
  c=fgetc(fp);
  p.c4=i=0;
  while(c!='\n')
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c4=atoi(nu);
  c=fgetc(fp);
  p.c5=i=0;
  while(c!='\n')
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c5=atoi(nu);
  c=fgetc(fp);
  p.c6=i=0;
  while(c!='\n')
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c6=atoi(nu);
  c=fgetc(fp);
  p.c7=i=0;
  while(c!=EOF)
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  p.c7=atoi(nu);
  fclose(fp);
  if(rw=='r')
  {
    switch(ch)
    {
      case 'a':strcpy(s,p.c1);break;
      case 'b':return p.c2;
      case 'c':return p.c3;
      case 'd':return p.c4;
      case 'e':return p.c5;
      case 'f':return p.c6;
      case 'g':return p.c7;
      default :return -1;
    } 
  }
  else if(rw=='w')
  {
    fp=fopen("option","w");
    switch(ch)
    {
      case 'a':fprintf(fp,"%s\n",s);break;
      case 'b':p.c2=atoi(s);break;
      case 'c':p.c3=atoi(s);break;
      case 'd':p.c4=atoi(s);break;
      case 'e':p.c5=atoi(s);break;
      case 'f':p.c6=atoi(s);break;
      case 'g':p.c7=atoi(s);break;
      default :return -1;
    }
    if(ch!='a')fprintf(fp,"%s\n",p.c1);
    fprintf(fp,"%ld\n",p.c2);
    fprintf(fp,"%ld\n",p.c3);
    fprintf(fp,"%ld\n",p.c4);
    fprintf(fp,"%ld\n",p.c5);
    fprintf(fp,"%ld\n",p.c6);
    fprintf(fp,"%ld",p.c7);
    fclose(fp);
    return 1;
  }
  return -1; 
}
void fun()
{
  char c,rw,s[100]="222";
  //scanf("%c %c %s",&c,&rw,s);
  c='b';rw='r';
  if(c=='a')
  {
    option(c,rw,s);
    printf("%s",s);
  }
  else
  {
    printf("%ld",option(c,rw,s));
  }
}
int main()
{
    fun();
}
