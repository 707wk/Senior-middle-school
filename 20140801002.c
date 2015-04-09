//用于读取已压缩的视频二进制文件，将其转换为文本文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OXOO "0123456789ABCDEF"

typedef struct node 
{
    char ch ;
    struct node*next ;
}
NODE ;


void putnode(NODE*head,int len)
{
    head=head->next ;
    for(;len;len--)
    {
        printf("%d ",head->ch);
        head=head->next ;
    }
    printf("\n");
}


int checkstr(NODE*head,int len)
{
    char str[]="\0\0\0\1" ;
    for(;len;len--)
    {
        if(head->ch!=str[4-len])return 0 ;
        head=head->next ;
    }
    return 1 ;
}


int main()
{
    FILE*fpin ;
    FILE*fpout ;
    NODE bits[5];
    NODE*p=bits+4 ;
    NODE*temp ;
    int i ;
    for(i=0;i<4;i++)
    {
        bits[i].ch=(char)*\ 0xff*;
        bits[i].next=&bits[i+1];
    }
    bits[i].ch=(char)*\ 0xff*;
    bits[i].next=bits ;
    //fpin = fopen("test.264", "rb");
    fpin=fopen("test——mobile.264","rb");
    if(fpin==NULL)
    {
        printf("error: files can not open!\n");
        exit(1);
    }
    //fpout = fopen("test.264.txt", "w");
    fpout=fopen("test——mobile.264.txt","w");
    for(i=0;i<4;i++)
    {
        fscanf(fpin,"%c",&bits[i].ch);
    }
    for(;!feof(fpin);)
    {
        fscanf(fpin,"%c",&p->ch);
        if(checkstr(p->next,4))
        {
            if(ftell(fpin)>6)
            fprintf(fpout,"\n");
        }
        fprintf(fpout,"%c%c ",OXOO[(p->next->ch&0xf0)>>4],OXOO[p->next->ch&0x0f]);
        temp=p=p->next ;
    }
    for(temp=temp->next;temp->next!=p;temp=temp->next)
    {
        fprintf(fpout,"%c%c ",OXOO[(temp->ch&0xf0)>>4],OXOO[temp->ch&0x0f]);
    }
    fclose(fpin);
    fclose(fpout);
    printf("ok");
    getchar();
    return 0 ;
}
