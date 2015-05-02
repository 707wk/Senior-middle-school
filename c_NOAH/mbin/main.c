#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct number
{
  int num;
  struct number *next;
};
int mbin(int m,int n)
{
  struct number *p,*q,*head1,*head2,*p2,*q2,*tmp,*tmp2;
  int i,j,s=1;
  head1=q=malloc(sizeof(struct number));
  head2=q2=malloc(sizeof(struct number));
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
  for(j=m;j>(m-n);j--)
  {
    if(j>(m-n+1))
    {
      q2->num=j;
      p2=malloc(sizeof(struct number));
      q2->next=p2;
      q2=p2;
    }
    else
    {
      q2->num=j;
      q2->next=NULL;
    }
  }
  tmp2=head2;
  while(tmp2!=NULL)
  {
    tmp=head1;
    while(tmp!=NULL)
    {
      if(tmp2->num%tmp->num==0)
      {
        tmp2->num=tmp2->num/tmp->num;
        tmp->num=1;
      }
      tmp=tmp->next;
    }
    s=s*tmp2->num;
    tmp2=tmp2->next;
  }
  return s;
}
int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  printf("%d",mbin(m,n));
}
