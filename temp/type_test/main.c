#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void getpos(HANDLE hOut,COORD *pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo( hOut , &info );
    *pos = info.dwCursorPosition;
}

void gotopos(HANDLE hOut,COORD pos)
{
    SetConsoleCursorPosition(hOut, pos);
}

int main()
{
	FILE* fp;
	HANDLE hOut;
    COORD pos;
    
	if((fp=fopen("data\\type.db","r"))==NULL)
	{
		printf("error , data\\type.db can not open ! \n");
		getchar();
		exit(0);
	}
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	getchar();
	return 0;
}
