/**************************************
 *FILE    :Source_any.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :5/7/2015
 *TEXT    :ת���ı�����Ϊ������
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

			// ��������ļ���β��û���꣬˵������Դ�� 
			if (feof(fpin))goto _FILES_IS_END_;

			//����Ƿ���0��1������������ 
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

//���ҵ�ǰĿ¼������txt�ļ� 
char** EnumFiles(const char* directory,int* count)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    char result[MAX_RESULT][MAX_PATH];
    char** returnresult;
    char pattern[MAX_PATH];
    int i=0;
	int j;
    
    // ��ʼ����
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
    
    // ���ҽ���
    FindClose(hFind);
    
    // ���Ƶ������
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
	
	//��ȡ��ǰ·�� 
	strcpy(directory,argv[0]);
	q=directory+strlen(argv[0]);
	while(*q!='\\')q--;
	*q='\0';
    
    //���ز��ҽ�� 
    result=EnumFiles(directory,&count);
    
    //����dataĿ¼ 
    CreateDirectory(".//data",NULL);
    
    printf("�Ѵ���");
    for(i=0;i<count;i++)
    {
    	changedata(result[i]);
    	printf("%2d%%\b\b\b",i*100/count);
    }
    
    printf("\r�ļ��������\n");
    Sleep(4000);
    return 0;
}
