#include<stdio.h>
void mai(int x,int y,int z)
{
    struct study
    {
        //动态创建循环链表求耶稣的叛徒（最终完美版）
        int num;
        struct study *next;
    };
    struct study *p,*q,*head;
    int i,n=0,s=x,h;
    p=q=head=(struct study *)malloc(sizeof(struct study)*1);
    s--;
    for(; s>0; s--)
    {
        q=p;
        p=(struct study *)malloc(sizeof(struct study)*1);
        q ->next=p;
    }
    p ->next=head;
    p=head;
    for(h=y-1; h>0; h--)
    {
        p=p ->next;
    }
    for(i=0; i<x; i++)
    {
        p ->num=i+1;
        p=p ->next;
    }
    p=head;
    s=x;
    for(n=0;;)
    {
        if(p ->num!=0)n++;
        if(z==n)
        {
            printf("%3d 不是那个数\n",p ->num);
            p ->num=0;
            n=0;
            s--;
        }
        if(s==1)break;
        p=p ->next;
    }
    p=head;
    for(i=0; i<x; i++)
    {
        if(p ->num!=0)printf("那个数是 :%3d",p ->num);
        p=p ->next;
    }
}
void main()
{
    int x,y,z;
    printf("动态创建循环链表求耶稣的叛徒（最终完美版）\n");
    printf("总人数: ");
    scanf("%d",&x);
    printf("开始位置: ");
    scanf("%d",&y);
    printf("间隔:   ");
    scanf("%d",&z);
    mai(x,y,z);
    getch();
}
