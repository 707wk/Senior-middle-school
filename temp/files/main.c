#include<stdio.h>
int main()
{
    int sum;
    FILE *fp;
    if((fp=fopen("abc.txt","r"))==NULL)return ;
    for(sum=0;!feof(fp);)
    {
        fgetc(fp);
        sum++;
    }
    printf("%3d",sum);
    fclose(fp);

    if((fp=fopen("abc.txt","r"))==NULL)return ;
    for(sum=0;fgetc(fp)!=EOF;)
    {
        sum++;
    }
    printf("%3d",sum);
    fclose(fp);
    getchar();
    return 0;
}
