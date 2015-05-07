/**************************************
 *FILE    :Source_any.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :5/7/2015
 *TEXT    :转换文本数据为二进制
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/

#undef UNICODE 
#define MAX_RESULT 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int sumtwo(char* str)
{
	int sum = 0;
	int i;
	str = str + 7;
	for (i = 0; i < 8; i++)
	{
		sum += ((*str - '0') << i);
		str--;
	}
	return sum;
}

void changedata(char* inputfiles)
{
	int i;
	char ch;
	FILE* fpin;
	FILE* fpout;
	char str[8];

	char outputfiles[MAX_PATH]="data\\";
	
	fpin = fopen(inputfiles, "rb");
	if (fpin == NULL)
	{
		printf("error: files can not open!\n");
		getchar();
		exit(1);
	}

	strcat(outputfiles,inputfiles);

	int len=strlen(outputfiles)-3;
	outputfiles[len]='\0';
	strcat(outputfiles,"264");
		
	fpout = fopen(outputfiles, "wb");
	while (!feof(fpin))
	{
		for (i = 0; i<8; i++)
		{
			ch = fgetc(fpin);

			// 如果读到文件结尾还没读完，说明数据源损坏 
			if (feof(fpin))goto _FILES_IS_END_;

			//检测是否是0或1，不是则跳过 
			if (ch == '0' || ch == '1')
				str[i] = ch;
			else i--;
		}
		// write to file after conversion 
		fprintf(fpout, "%c", sumtwo(str));
	}
_FILES_IS_END_:

	fclose(fpin);
	fclose(fpout);
}

//查找当前目录下所有txt文件 
char** EnumFiles(const char* directory,int* count)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    char result[MAX_RESULT][MAX_PATH];
    char** returnresult;
    char pattern[MAX_PATH];
    int i=0;
	int j;
    
    // 开始查找
    strcpy(pattern,directory);
    strcat(pattern,"\\*.txt");
    hFind=FindFirstFile(pattern,&FindFileData);
    
    if(hFind==INVALID_HANDLE_VALUE)
    {
        *count=0 ;
        return NULL ;
    }
    else 
    {
        do 
        {
            strcpy(result[i++],FindFileData.cFileName);
        }
        while(FindNextFile(hFind,&FindFileData)!=0);
    }
    
    // 查找结束
    FindClose(hFind);
    
    // 复制到结果中
    returnresult=(char**)calloc(i,sizeof(char*));
    
    for(j=0;j<i;j++)
    {
        returnresult[j]=(char*)calloc(MAX_PATH,sizeof(char));
        strcpy(returnresult[j],result[j]);
    }
    
    *count=i ;
    return returnresult ;
}

int main(int argc,char* argv[])
{
    int i;
	int count ;
    char**result ;
    char directory[MAX_PATH];
	char* q;
	
	//获取当前路径 
	strcpy(directory,argv[0]);
	q=directory+strlen(argv[0]);
	while(*q!='\\')q--;
	*q='\0';
    
    //返回查找结果 
    result=EnumFiles(directory,&count);
    
    //创建data目录 
    CreateDirectory(".//data",NULL);
    
    printf("已处理");
    for(i=0;i<count;i++)
    {
    	changedata(result[i]);
    	printf("%2d%%\b\b\b",i*100/count);
    }
    
    printf("\r文件处理完毕\n");
    Sleep(4000);
    return 0;
}
