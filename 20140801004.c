//分隔二进制文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OXOO "0123456789ABCDEF"


int main()
{
    FILE*fpin ;
    FILE*fpout ;
    char str[5];
    char temp ;
    int i ;
    fpin=fopen("test.264","rb");
    if(fpin==NULL)
    {
        printf("error: files can not open!\n");
        exit(1);
    }
    fpout=fopen("test.264.txt","w");
    fscanf(fpin,"%c%c%c%c",str,str+1,str+2,str+3);
    //读取数据中00 00 00 01这一部分
    for(;!feof(fpin);)
    {
        fscanf(fpin,"%c",&temp);
        //读取后面一个字节的数据
        fprintf(fpout,"00 00 00 01 %c%c ",OXOO[(temp&0xf0)>>4],OXOO[temp&0x0f]);
        //输出00 00 00 01 ** 到文件
        for(str[4]=*\ 0*;!feof(fpin);)
        {
            fscanf(fpin,"%c%c%c%c",str,str+1,str+2,str+3);
            //每次读取4个字节的数据
            if(strcmp("\0x00\0x00\0x00\0x01",str)==0)break ;
            for(i=0;i<4;i++)
            {
                fprintf(fpout,"%c%c ",OXOO[(str[i]&0xf0)>>4],OXOO[str[i]&0x0f]);
                //每次输出一个字节(以16进制字符格式)到文件
            }
        }
        fprintf(fpout,"\n");
        //换到下一行
    }
    fclose(fpin);
    fclose(fpout);
    printf("ok");
    getchar();
    return 0 ;
}
