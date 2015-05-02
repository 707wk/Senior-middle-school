/**************************************
 *FILE    :main.c
 *PROJECT :ysdpt
 *AUTHOR  :707wk
 *TEXT    :输入总人数 开始号码 间隔人数
 *CREATED :4/29/2013
***************************************/
#include<stdio.h>
#include<malloc.h>
struct number
{
  int num;
  struct number *next;
};
int jesus(int num,int start,int gap)
{
  int i,j=num,n=1;
  struct number *p,*q,*head;
  head=q=malloc(sizeof(struct number));
  for(i=1;i<=num;i++)
  {
    if(i!=num)
    {
      q->num=i;
      p=malloc(sizeof(struct number));
      q->next=p;
      q=p;
    }
    else 
    {
      q->num=i;
      q->next=head;
    }
  }
  p=head;
  while(start>1)
  {
    p=p->next;
    start=start-1;
  }
  while(j>1)
  {  
     if(p->num!=0)
     {
       if(n%gap==0)
       {
         p->num=0;
         n=1;
         j=j-1;
       }
       else n=n+1;
     }
     p=p->next;
  } 
  p=head;
  for(i=0;i<num;i++)
  {
    if(p->num!=0)printf("%d",p->num);
    p=p->next;
  }
}
int main(int argc, char *argv[])
{
  int num,start,gap;
  scanf("%d%d%d",&num,&start,&gap);
  jesus(num,start,gap);
  getch();
}
