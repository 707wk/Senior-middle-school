#include<stdio.h>
int inputnum(int a[])
{
    int s=0,n=0;
    char c;
    for(c=getchar();;c=getchar())
    {
        if(c==' '||c=='\n'){*a=s;a++;n++;s=0;}
        else s=s*10+c-'0';
        if(c=='\n')break;
    }
	return n;
}

