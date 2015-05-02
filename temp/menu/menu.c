#include<stdio.h>
#include<windows.h>
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
	char c;
	int i=0;
	HANDLE hOut;
    COORD pos;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X=0;
	pos.Y=0;
	//gotopos(hOut,pos);
	printf("   Õý³£Á·Ï°\n   ´íÌâÁ·Ï°\n");
	gotopos(hOut,pos);
	printf(">\b");
    while((c=getch())=='\r');
	while(c!='\r')
	{
		switch(c)
		{
			case 75:
			case 72:
			{
				gotopos(hOut,pos);
				printf("\b \b");
				i--;
				if(i<0)i=1;
				pos.Y=i;
				gotopos(hOut,pos);
				printf(">\b");
				break;
			}
			case 77:
			case 80:
			{
				gotopos(hOut,pos);
				printf("\b \b");
				i++;
				if(i>1)i=0;
				pos.Y=i;
				gotopos(hOut,pos);
				printf(">\b");break;
			}
		}
		c=getch();
	}
	return 0;
}
