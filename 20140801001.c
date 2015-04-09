//计算数据波动
#include <stdio.h>
#include <math.h>

typedef struct 
{
    char name[100];
    double variance ;
}
FILESNAME ;


void input_filesname(FILESNAME*head,int num)
{
    int i ;
    /*printf("input filename:\n");*/
    for(i=0;i<num;i++)
    {
        sprintf(head[i].name,"motion vector %d.txt",1+i);
        puts(head[i].name);
        head[i].variance=0.0 ;
    }
    printf("----------------------------------------\n");
}


void read_data(FILESNAME*head,int num)
{
    FILE*fp ;
    int temp[3];
    int i ;
    int j ;
    for(j=0;j<num;j++)
    {
        fp=fopen(head[j].name,"rb");
        if(fp==NULL)
        {
            printf("files %s not find!\n",head[j].name);
            fclose(fp);
            continue ;
        }
        else printf("%s\n",head[j].name);
        while(!feof(fp))
        {
            for(i=0;i<3;i++)
            {
                fscanf(fp,"%d,%d,%d|",&temp[0],&temp[1],&temp[2]);
                head[j].variance+=sqrt(temp[0]*temp[0]+temp[1]*temp[1]+temp[2]*temp[2]);
            }
            fscanf(fp,"%d,%d,%d\n",&temp[0],&temp[1],&temp[2]);
            head[j].variance+=sqrt(temp[0]*temp[0]+temp[1]*temp[1]+temp[2]*temp[2]);
        }
        fclose(fp);
        printf("\t%f\n",head[j].variance);
    }
}


void put_num(FILESNAME*head,int num)
{
    int i ;
    for(i=0;i<num;i++)
    {
        printf("%2d:%s:%10.3f\n",i+1,head[i].name,head[i].variance);
    }
}


int main(int argc,char*argv[])
{
    FILESNAME files[32];
    input_filesname(files,32);
    read_data(files,32);
    put_num(files,32);
    getchar();
    return 0 ;
}
