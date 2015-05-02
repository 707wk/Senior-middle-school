#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "snake.h"

int main()
{
    HANDLE hThrd;
    DWORD threadId;
    flage=4;
    time_interval=10;
    hThrd=CreateThread(NULL,0,snake,(LPVOID)0,0,&threadId);
    for(;;)
    {
        switch(getch())
        {
        case 224:
            switch(getch())
            {
            case 72:
                if(flage!=2&&flage>0)
                {
                    flage=1;
                }
                break;
            case 80:
                if(flage!=1&&flage>0)
                {
                    flage=2;
                }
                break;
            case 75:
                if(flage!=4&&flage>0)
                {
                    flage=3;
                }
                break;
            case 77:
                if(flage!=3&&flage>0)
                {
                    flage=4;
                }
                break;
            }
            break;
        case 32:
            flage=-flage;
            break;
        case 'w':
            if(time_interval<200)
            {
                time_interval=time_interval+1;
            }
            break;
        case 'e':
            if(time_interval>1)
            {
                time_interval=time_interval-1;
            }
            break;
        }
        Sleep(100);
    }
    getchar();
    return 0;
}
