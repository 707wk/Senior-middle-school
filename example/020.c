//20��һͷСţ����󳤴�Ȼ����һͷСţ���Ժ�ÿ�궼��һͷţ�����ʵ�ʮ���ж���ͷţ��
#include<stdio.h>      
int fun(int n)
{
    int sum=0,i;
    if(n<4)return 1;
    for(i=1;i<=n;i++)
    {
        if(i<4)sum=1;
        else sum=sum+fun(n-i+1);
    }
    return sum;
}
int main()
{
    printf("10�����%dͷţ\n",fun(10));
    getchar();
    return 0;
}
