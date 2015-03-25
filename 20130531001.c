/**************************************
 *FILE    :main.c
 *PROJECT :014
 *AUTHOR  :707wk
 *CREATED :5/28/2013
 *TEXT :二路合并
***************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fun(int *a,int *b)
{
  struct number
  {
    int num;
    struct number *next;
  };
  struct number *p,*q,*head;
  int *db=a;
  p=q=head=malloc(sizeof(struct number));
  while(*a||*b)
  {
    if(*a==0||b==0)break;
    if(*a<=*b)
    {
      q->num=*a;
      a++;
    }
    else 
    {
      q->num=*b;
      b++;
    }
    p=malloc(sizeof(struct number));
    q->next=p;
    q=p;
  }
  if(!*a)while(*b)
        {
          q->num=*b;
          if(*(b+1))
          {
            p=malloc(sizeof(struct number));
            q->next=p;
            q=p;
          }
          else q->next=NULL;
          b++;
        }
  else while(*a)
       {
         q->num=*a;
         if(*(a+1))
         {
           p=malloc(sizeof(struct number));
           q->next=p;
           q=p;
         }
         else q->next=NULL;
         a++;
       }
  q=head;
  a=db;
  while(q!=NULL)
  {
    *a=q->num;
    a++;
    q=q->next;
  }
}
int main(int argc, char *argv[])
{
  int i,a[10]={1,3,5,7,8,8,9},b[10]={6,8,10};
  fun(a,b);
  system("clear");
  for(i=0;i<10;i++)printf("%3d",a[i]);
}
