#include<stdio.h>
#include<malloc.h>
int main()
{
  struct ber
  {
    int num;
    struct ber *next;
  };
  int n=10,m,k=1;
  struct ber *p,*q,*head;
  head=q=malloc(sizeof(struct ber));
  for(m=0;m<n-1;m++)
  {
    p=malloc(sizeof(struct ber));
    q->next=p;
    q=p;
  }
  p->next=head;
  p=head;
  for(m=1;m<10;m++)
  {
    p->num=1;
    p=p->next;
  }
  p=head;
  while(n>1)
  {
    if(k%3==0)
  {
    p->num=0;
    n--; 
  }
  k++;
  p=p->next;
  }
  for(m=0;m<10;m++)
  {
    if(p->num!=0)printf("%d",p->num);
  }
}
