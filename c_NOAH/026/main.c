/**************************************
 *FILE    :main.c
 *PROJECT :026
 *AUTHOR  :707wk
 *CREATED :9/15/2013
***************************************/
/*
winҪ����windows.h,Unix����unistd.h,��sleep()����
win��sleep��΢����,unix��sleep������,΢��(ǧ��֮һ��ǧ��֮һ��)��usleep()
VC��Sleep, ���һ��ʹ��sleep
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
	printf ( "������%4d��%02d��%02d��%02dʱ%02d��%02d��\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
	printf("��2014��߿�����%2d��\n",date(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday));
	//if(n)puts("����������");
	//else puts("δ��������");
	sleep(1);
	}
	//system("killall embeddedkonsole");
	return 0;
}
