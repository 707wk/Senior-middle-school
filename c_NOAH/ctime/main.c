/*
winҪ����windows.h,Unix����unistd.h,��sleep()����
win��sleep��΢����,unix��sleep������,΢��(ǧ��֮һ��ǧ��֮һ��)��usleep()
VC��Sleep, ���һ��ʹ��sleep
0=��ɫ 8=��ɫ
1=��ɫ 9=����ɫ
2=��ɫ A=����ɫ
3=ǳ��ɫ B=��ǳ��ɫ
4=��ɫ C=����ɫ
5=��ɫ D=����ɫ
6=��ɫ E=����ɫ
7=��ɫ F=����ɫ
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
		case 1:printf("          ����������һ           %c\n",3);break;
		case 2:printf("          ���������ڶ�           %c\n",3);break;
		case 3:printf("          ������������           %c\n",3);break;
		case 4:printf("          ������������           %c\n",3);break;
		case 5:printf("          ������������           %c\n",3);break;
		case 6:printf("          ������������           %c\n",3);break;
		case 0:printf("          ������������           %c\n",3);break;
	}
	pri();
}
void text(int year,int mon,int day)
{
    switch(mon)
    {
        case  1 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);break;
        case  2 :break;
        case  3 :if(day==12)printf("                           %c  �������ҵ�%d������  %c\n",3,year-1995,3);
                    if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);
                    else printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case  4 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);
                    else printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case  5 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);break;
        case  6 :break;
        case  7 :break;
        case  8 :break;
        case  9 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);
                    else printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 10 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);
                    else printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 11 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);
                    else printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon+1,Dayinmonth(mon,year)-day+20,3);break;
        case 12 :if(day<21)printf("                           %c��%d��%d���¿�����%d��%c\n",3,year,mon,21-day,3);
                    else if(day==21||day==22)printf("                           %c������%d��%d���¿���%d��%c\n",3,year,mon,day-20,3);break;
    }
}
void date(int year,int mon,int day)
{
    int sum=0,num=year;
    if((mon==6&&day>6)||(mon>6))num=year+1;
    for(;!(year==num&&mon==6);sum=sum+Dayinmonth(mon,year),mon++)if(mon>12){mon=1;year++;}
    printf("      ��%4d��߿�����%3d��      %c\n",num,sum+6-day,3);
}
int main ()
{
    time_t rawtime;
    struct tm * timeinfo;
    int i,n=0;
    system("color 0a");
	printf("�����С�����");
	if(system("ping -n 1 www.baidu.com  > nul")==0)n=1;
    for(i=0;i<10;i++)
	{
        system("cls");
        time(&rawtime);
        timeinfo=localtime(&rawtime);
        printf("\n\n\n\n\n\n\n                     %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
        pr();
        printf ( "������%4d��%02d��%02d��%02dʱ%02d��%02d�� %c\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,3);
        pri();
        week(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
		text(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
        pri();
        pr();
        date(1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday);
        pri();
        pr();
        if(n)printf("           ����������            %c\n",3);
        else printf("           ����δ����            %c\n",3);
        pri();
		Sleep(1000);
    }
}
