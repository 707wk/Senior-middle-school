#include<stdio.h>                   //砝码问题
int fun(int a0,int a1,int a2,int a3)
{
    int b[4],i,sum,c[40]={0};
    for(b[0]=-1;b[0]<2;b[0]++)
        for(b[1]=-1;b[1]<2;b[1]++)
            for(b[2]=-1;b[2]<2;b[2]++)
                for(b[3]=-1;b[3]<2;b[3]++)
                {
                    sum=b[0]*a0+b[1]*a1+b[2]*a2+b[3]*a3;
                    if(sum>0)c[sum-1]++;
                }
    for(i=0;i<40;i++)
        if(c[i]==0)return 0;
    return 1;
}
int main()
{
    int a[4];
    for(a[0]=1;a[0]<40;a[0]++)
        for(a[1]=1;a[1]<a[0];a[1]++)
            for(a[2]=1;a[2]<a[1];a[2]++)
            {
                a[3]=40-a[0]-a[1]-a[2];
                if(a[3]<=a[0]&&a[2]>a[3]&&a[3]>0&&fun(a[0],a[1],a[2],a[3]))
                    printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
            }
    getchar();
    return 0;
}
