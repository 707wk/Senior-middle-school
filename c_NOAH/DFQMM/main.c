#include<stdio.h>
#include<math.h>
#include"inputnum.h"
int DFQ(int *b,int num)
{
    for(;*b;b++)if(*b==num||num>33||num==0)return 0;
    return 1;
}
int main()
{
    int a[100]={0},b[200]={0};
    int n,*p,m,*i,*j,num;
	printf("������Ҫ�������:\n");
    n=inputnum(a);
    for(p=b,i=a;i<a+n;i++)
        for(j=i+1;j<a+n;j++)
        {
              if(DFQ(b,num=*i+*j)){*p=num;p++;}
              if(DFQ(b,num=abs(*i-*j))){*p=num;p++;}
              if(DFQ(b,num=*i*(*j))){*p=num;p++;}
              if(DFQ(b,num=*i/(*j))){*p=num;p++;}
        }
    for(system("cls"),printf("�������Ĵ����������:\n"),p=b,n=0;*p;p++,n++)
    {
        if(!(n%4))printf("\n");
        printf("%6d",*p);
    }
    getchar();
    return 0;
}
