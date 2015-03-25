#include<stdio.h>             //达芬奇密码（数组算法）
#include<math.h>
void fun(int a[],int n)
{
    int *p,*q,t;
    for(p=a;p-a<n-1;p++)
        for(q=p+1;q-a<n;q++)
            if(*p>*q){t=*p;*p=*q;*q=t;}
}
int DFQ(int *b,int num)
{
    for(;*b;b++)if(*b==num||num>33||num==0)return 0;
    return 1;
}
int DFQ1(int *a)
{
   if(!(*a))return 0;
   return DFQ1(a+1)+1;
}
int main()
{
    int a[100]={0},b[200]={0};
    int nu=0,n,*p,m,i,j,num;
    for(scanf("%d",&a[nu]);a[nu++]!=0;)scanf("%d",&a[nu]);
    for(n=DFQ1(a),p=b,i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            num=a[i]+a[j];if(DFQ(b,num)){*p=num;p++;}
            num=abs(a[i]-a[j]);if(DFQ(b,num)){*p=num;p++;}
            num=a[i]*a[j];if(DFQ(b,num)){*p=num;p++;}
            num=a[i]/a[j];if(DFQ(b,num)){*p=num;p++;}
        }
    for(fun(b,DFQ1(b)),system("cls"),p=b,i=0;*p;p++,i++)
    {
        if(!(i%4))printf("\n");
        printf("%6d",*p);
    }
    getchar();
    return 0;
}
