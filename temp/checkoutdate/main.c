#include <stdio.h>
#include <time.h> 
#include <windows.h>
int checkoutdate(int date_year , int date_mon , int date_day ) //����ʱ�䷵��1�����򷵻�0 
{
	int flag;
	time_t rawtime;
    struct tm * timeinfo;
   	time(&rawtime);
   	timeinfo=localtime(&rawtime);
    if( 1900+timeinfo->tm_year > date_year )
    {
    	return 1;
    }
    else if( 1900+timeinfo->tm_year == date_year )
    {
    	if( 1+timeinfo->tm_mon > date_mon )
    	{
    		return 1;
    	}
    	else if( 1+timeinfo->tm_mon == date_mon )
    	{
    		if( timeinfo->tm_mday > date_day )
    		{
    			return 1;
    		}
    	}
    }
    return 0;
}
int main()
{
	if(checkoutdate(2014,3,16))
	{
		printf("������ѳ���ʹ����\n");
		getchar();
		return 0;
	}
	printf("ok");
	getchar();
	return 0;
}
