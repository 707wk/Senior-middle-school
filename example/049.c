//49、编写函数求十个学生的平均成绩，并返回最大值，最小值。
#include<stdio.h>
float fun(int a[],int *max,int *min)
{
    int i;
    float aver=0;
    aver=*max=*min=a[0];
    for(i=1;i<10;i++)
    {
        if(*max<a[i])*max=a[i];
        if(*min>a[i])*min=a[i];
        aver+=a[i];
    }
    return aver/10;
}
int main()
{
    int a[10]={56,76,45,75,32,98,34,67,84,88},max,min;
    float aver=0;
    aver=fun(a,&max,&min);
    printf("max = %d\nmin = %d\naver = %f",max,min,aver);
    getchar();
    return 0;
}