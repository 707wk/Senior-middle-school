/*
winҪ����windows.h,Unix����unistd.h,��sleep()����
win��sleep��΢����,unix��sleep������,΢��(ǧ��֮һ��ǧ��֮һ��)��usleep()
VC��Sleep, ���һ��ʹ��sleep
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
printf ( "%4d��%02d��%02d��%02dʱ%02d��%02d��\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}
getch();
}
