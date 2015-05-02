//20、一头小牛四年后长大，然后生一头小牛，以后每年都生一头牛。请问第十年有多少头牛。
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
    printf("10年后共有%d头牛\n",fun(10));
    getchar();
    return 0;
}
