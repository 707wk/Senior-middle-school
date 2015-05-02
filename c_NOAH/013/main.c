/**************************************
 *FILE    :main.c
 *PROJECT :013
 *AUTHOR  :707wk
 *CREATED :5/28/2013
***************************************/
#include<stdio.h>
#include<stdlib.h>
void fun(int *a,int *b,int n)
{
  struct number
  {
    int num;
    struct number *next;
  };
  struct number *pa,*pb,*qa,*qb,*heada,*headb;
  pa=qa=heada=malloc(sizeof(struct number));
  pb=qb=headb=malloc(sizeof(struct number));
  while(*a!=0)
  {
    qa->num=*a;
    pa=malloc(sizeof(struct number));
    qa->next=pa;
    qa=pa;
    a++;
  }
  qa->next=NULL;
  while(*b)
  {
    qb->num=*b;
    pb=malloc(sizeof(struct number));
    qb->next=pb;
    qb=pb;
    b++;
  }
  qb->next=NULL;
  qa=heada;
  qb=headb;
  for(;n>0;n--)
  {
    if(qa->num<qb->num)
    {
      qa->next=qb;
      qa=qa->next;
      qb=qb->next;
    }
    else qa=qa->next;
  }
}
int main(int argc, char *argv[])
{
  int i,a[10]={1,2,3,6,9},b[5]={3,5,6,8,9,};
  fun(a,b,10);
  for(i=0;i<10;i++)printf("%d ",a[i]);
}
