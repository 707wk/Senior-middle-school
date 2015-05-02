#include<stdio.h>
#include<malloc.h>
struct number
{
  int num;
  struct number *next;
};
int sombin(int m,int n)
{
  struct number *p,*q,*head;
  int i;
  head=q=malloc(sizeof(struct number));
  for(i=1;i<=n;i++)
  {
    if(i!=n)
    {
      q->num=i;
      p=malloc(sizeof(struct number));
      q->next=p;
      q=p;
    }
    else
    {
      q->num=i;
      q->next=NULL;
    }
  } 
  q=head;
  while(q!=NULL)
  {
    printf("%3d",q->num);
    q=q->next;
  }
}
int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  sombin(m,n);
  /*printf("%d",sombin(m,n));*/
}