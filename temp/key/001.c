#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
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
    int i=0,j=0;
    HANDLE hOut;
    COORD pos;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X=0;
    pos.Y=0;
    gotopos(hOut,pos);
    printf("#\b");
    for(;;)
    {
        switch(getch())
        {
        case 'a':
            if(j>0)j--;
            break;
        case 'd':
            if(j<40)j++;
            break;
        case 'w':
            if(i>0)i--;
            break;
        case 's':
            if(i<10)i++;
            break;
        }
        printf(" ");
        pos.X=j;
        pos.Y=i;
        gotopos(hOut,pos);
        printf("#\b");
    }
}
