#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "include/checkdate.h"

#define _LINUX_

#ifdef _LINUX_
	#include <unistd.h>
	#include "include/getch.h"
#endif

void clear_type()
{
	system("busybox clear");
}

int ELFHash( char str[] ) 
{
	int hash=0  ;
	int x=0  ;
	int i  ;
	for( i=0 ; i<strlen( str ) ; i++  )
	{
		hash=( hash<<4 ) + str[i] ;
		if( ( x=( int )( hash&0xF0000000L ) ) != 0 )
		{
			hash^=( x>>24 ) ;
			hash&=~x  ;
		}
	}
	return( hash&0x7FFFFFFF ) ;
}

char* get_str(char* str,int len)
{
	char c;
	char *p=str;
	while(len>0&&c=getchar()!='\n')
	{
		*str++=c;
		len--;
	}
	*str='\0';
	while(c!='\n')
	{
		c=getchar();
	}
	return p;
}

void check_load()
{
	char user_name[100];
	char passwd[20];
	printf("server IP address : ");
	printf("user name : ");
	printf("password : ");
	clear_type();
}

int main(int argc,char* argv[])
{
	check_load();
	for(;;)
	{
	}
	return 0;
}
