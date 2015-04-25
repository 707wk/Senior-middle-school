/**************************************
 *FILE    :Source.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/25/2015
 *TEXT    :ascii to bits
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	int i;
	char ch;
	FILE* fpin;
	FILE* fpout;
	char str[8];
	
	//数据源 
	//fpin = fopen("test.264.txt", "rb");
	fpin = fopen("rush_hour_fmo.txt", "rb");
	if (fpin == NULL){
		printf("error: files can not open!\n");
		exit(1);
	}
	
	//输出文件 
	//fpout = fopen("test.264", "wb");
	fpout = fopen("rush_hour_fmo.264", "wb");
	while (!feof(fpin))
	{
		for(i=0;i<8;i++)
		{
			ch=fgetc(fpin);
			
			//如果读到文件结尾还没读完，说明数据源损坏 
			if(feof(fpin))goto _FILES_IS_END_;
			
			//检测是否是0或1，不是则跳过 
			if(ch=='0'||ch=='1')
				str[i]=ch;
			else i--;
		}
		//将转换后的写入到文件 
		fprintf(fpout, "%c", sumtwo(str));
	}
	_FILES_IS_END_:
	
	fclose(fpin);
	fclose(fpout);
	printf("ok");
	getchar();
	return 0;
}

