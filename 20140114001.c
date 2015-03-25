#include<stdio.h>                        //按成绩排序(使用TC编译)(1)
#include<stdlib.h>
#define PEOPLE 20
#define NUM_CLASS 2
struct student
{
    int clas;
    int sum;
};
int main()
{
    struct student a[PEOPLE],t;
    int i,j,n,m,temp;
    randomize();system("GRAFTABL 936>w\nDEL w");
    for(i=0;i<PEOPLE;i++)
    {
        a[i].clas=random(NUM_CLASS)+1;
        a[i].sum=random(100)+1;
    }
    for(i=0;i<PEOPLE-1;i++)
    {
        for(j=0;j<PEOPLE-i-1;j++)
            if(a[j].clas>a[j+1].clas)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    for(temp=a[0].clas,n=0;n<PEOPLE;n=m)
    {
        for(temp=a[n].clas,m=n;(a[m].clas==temp)&&m<PEOPLE;m++);
        for(i=n;i<m-2;i++)
            for(j=n;j<m-i+n-1;j++)
                if(a[j].sum<a[j+1].sum)
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
    }
    for(printf("班级 成绩 排名\n"),i=0;i<PEOPLE;i++)
    {
        for(n=1,j=0;j<PEOPLE;j++)
            if(a[j].sum>a[i].sum&&a[i].clas==a[j].clas)n++;
        printf("%3d%5d%4d\n",a[i].clas,a[i].sum,n);
        if(a[i].clas!=a[i+1].clas&&i<PEOPLE-1)
            printf(">------------<\n");
    }
    getchar();
    return 0;
}
