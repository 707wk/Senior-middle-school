/*
win要包含windows.h,Unix包含unistd.h,用sleep()函数
win的sleep按微秒算,unix的sleep按秒算,微秒(千分之一的千分之一秒)是usleep()
VC用Sleep, 别的一律使用sleep
0=黑色 8=灰色
1=蓝色 9=淡蓝色
2=绿色 A=淡绿色
3=浅绿色 B=淡浅绿色
4=红色 C=淡红色
5=紫色 D=淡紫色
6=黄色 E=淡黄色
7=白色 F=亮白色
*/
#include <stdio.h>
#include <time.h> 
#include<windows.h> 
#include"checkdate.h"
#define pr() printf("                     %c  ",3)
#define pri() printf("                     %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3)
void week(int year,int mon,int day)
{
	int sum=0,y=2013,m=9,d=29;
    for(;!(year==y&&mon==m);sum=sum+Dayinmonth(m,y),m++)if(m>12){m=0;y++;}
	pr();
	switch((sum+day-d)%7)
	{
		case 1:printf("          今天是星期一           %c\n",3);break;
		case 2:printf("          今天是星期二           %c\n",3);break;
		case 3:printf("          今天是星期三           %c\n",3);break;
		case 4:printf("          今天是星期四           %c\n",3);break;
		case 5:printf("          今天是星期五           %c\n",3);break;
		case 6:printf("          今天是星期六           %c\n",3);break;
		case 0:printf("          今天是星期日           %c\n",3);break;
	}
	pri();
}
void text(int year,int mon,int day)
{
    switch(mon)
    {
        case  1 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);break;
        case  2 :break;
        case  3 :if(day==12)printf("                           %c  今天是我的%d岁生日  %c\n",3,year-1995,3);
                    if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);
                    else printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case  4 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);
                    else printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case  5 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);break;
        case  6 :break;
        case  7 :break;
        case  8 :break;
        case  9 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);
                    else printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 10 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);
                    else printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 11 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);
                    else printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 12 :if(day<21)printf("                           %c距%d年%d月月考还有%d天%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c今天是%d年%d月月考第%d天%c\n",3,year,mon,day-20,3);break;
    }
}
void date(int year,int mon,int day)
{
    int sum=0,num=year;
    if((mon==6&&day>6)||(mon>6))num=year+1;
    for(;!(year==num&&mon==6);sum=sum+Dayinmonth(mon,year),mon++)if(mon>12){mon=1;year++;}
    printf("      离%4d年高考还有%3d天      %c\n",num,sum+6-day,3);
}
int main ()
{
    time_t rawtime;
    struct tm * timeinfo;
    int i,n=0;
    system("color 0a");
	printf("启动中。。。");
	if(system("ping -n 1 www.baidu.com  > nul")==0)n=1;
    for(i=0;i<10;i++)
	{
        system("cls");
        time(&rawtime);
        timeinfo=localtime(&rawtime);
        printf("\n\n\n\n\n\n\n                     %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
        pr();
        printf ( "现在是%4d年%02d月%02d日%02d时%02d分%02d秒 %c\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,3);
        pri();
        week(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
		text(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
        pri();
        pr();
        date(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
        pri();
        pr();
        if(n)printf("           网络已连接            %c\n",3);
        else printf("           网络未连接            %c\n",3);
        pri();
		Sleep(1000);
    }
}
