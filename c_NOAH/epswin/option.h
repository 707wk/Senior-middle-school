#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long option(char rw,long nb)
{
  char c,nu[200]="abc";
  long i=0;
  FILE *fp;
  fp=fopen("option","r");
  c=fgetc(fp);
  while(c!=EOF)
  {
    nu[i]=c;
    i++;
    c=fgetc(fp);  
  }
  nu[i]='\0';
  fclose(fp);
  if(rw=='r')return atoi(nu);
  else if(rw=='w')
  {
    fp=fopen("option","w");
    fprintf(fp,"%ld",nb);
    fclose(fp);
    return 1;
  }
  return -1; 
}
