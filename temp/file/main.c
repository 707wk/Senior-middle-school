#include<stdio.h>
int main()
{
FILE *fp;
int a[3];
fp=fopen("option","r");
fscanf(fp,"num = %d\ntextcolor = %d\ntextbackground = %d",&a[0],&a[1],&a[2]);
printf("%d.%d.%d",a[0],a[1],a[2]);
getchar();
return 0;
}
