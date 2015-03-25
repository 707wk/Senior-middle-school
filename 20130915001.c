/**************************************
 *FILE    :main.c
 *PROJECT :026
 *AUTHOR  :707wk
 *CREATED :9/15/2013
***************************************/
/*
win要包含windows.h,Unix包含unistd.h,用sleep()函数
win的sleep按微秒算,unix的sleep按秒算,微秒(千分之一的千分之一秒)是usleep()
VC用Sleep, 别的一律使用sleep
*/
#include <stdio.h>
#include <time.h> 
//#include<windows.h> 
#include<unistd.h>
#include"checkdate.h"
int date(int year,int mon,int day)
{
	int sum=0;
	while(!(year==2014&&mon==6))
	{
		if(mon>12){mon=1;year++;}
		sum=sum+Dayinmonth(mon,year);
		mon++;
	}
	return sum+6-day;
}
int main(int argc, char *argv[])
{
	time_t rawtime;
	struct tm * timeinfo;
	int i,n=0;
	for(i=0;i<10;i++)
	{
	//if(system("ping -n 1 gtsoft.cwsurf.de  > nul")==0)n=1;
	//else n=0;
	system("clear");
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf ( "现在是%4d年%02d月%02d日%02d时%02d分%02d秒\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
	printf("离2014年高考还有%2d天\n",date(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday));
	//if(n)puts("网络已连接");
	//else puts("未连接网络");
	sleep(1);
	}
	//system("killall embeddedkonsole");
	return 0;
}
