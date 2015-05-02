/*
win要包含windows.h,Unix包含unistd.h,用sleep()函数
win的sleep按微秒算,unix的sleep按秒算,微秒(千分之一的千分之一秒)是usleep()
VC用Sleep, 别的一律使用sleep
*/
#include <stdio.h>
#include <time.h> 
#include<windows.h>
void main ()
{
time_t rawtime;
struct tm * timeinfo;
for(;;){
Sleep(1000);
time ( &rawtime );
system("cls");
timeinfo = localtime ( &rawtime );
printf ( "%4d年%02d月%02d日%02d时%02d分%02d秒\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}
getch();
}
