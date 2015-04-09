//文本转二进制
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OXOO "0123456789ABCDEF"


int reoxoo(char ch)
{
    int i ;
    for(i=0;i<16;i++)
    {
        if(ch==OXOO[i])return i ;
    }
    return 0 ;
}


int main()
{
    FILE*fpin ;
    FILE*fpout ;
    char str[2];
    fpin=fopen("test.264.txt","rb");
    if(fpin==NULL)
    {
        printf("error: files can not open!\n");
        exit(1);
    }
    fpout=fopen("test.264","wb");
    for(;!feof(fpin);)
    {
        fscanf(fpin,"%s",str);
        fprintf(fpout,"%c",16*reoxoo(str[0])+reoxoo(str[1]));
    }
    fclose(fpin);
    fclose(fpout);
    printf("ok");
    getchar();
    return 0 ;
}
