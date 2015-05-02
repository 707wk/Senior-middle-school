/*
 * Copyright 2014 wangk <1174843091@qq.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>

typedef struct
{
	int hour;
	int min;
}DATE;

typedef struct node
{
	char str[100];
	DATE start;
	DATE end;
	struct node* next;
}DATA;

void work_place(char* str)
{
	char* temp;
	char* q;puts(str);
	temp=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp,str);
	q=temp+strlen(str);
	while(*q!='/')q--;
	*q='\0';
	chdir(temp);
}

DATA* read_data()
{
	FILE* fpin;
	DATA* head;
	DATA* p;
	DATA* q;
	fpin=fopen("time.data","r");
	if(fpin==NULL)
	{
		printf("error	:	files time.data can not open !\n");
		exit(1);
	}
	head=p=(DATA*)malloc(sizeof(DATA));
	fscanf(fpin,"%s\t%d:%d\t%d:%d\n",
			p->str,
			&p->start.hour,&p->start.min,
			&p->end.hour,&p->end.min);
	for(;!feof(fpin);)
	{
		q=p;
		p=(DATA*)malloc(sizeof(DATA));
		fscanf(fpin,"%s\t%d:%d\t%d:%d\n",
				p->str,
				&p->start.hour,&p->start.min,
				&p->end.hour,&p->end.min);
		q->next=p;		
	}
	p->next=NULL;
	return head;
}

void put_data(DATA* head)
{
	while(head!=NULL)
	{
		printf("%s %d:%d %d:%d\n",head->str,head->start.hour,head->start.min,head->end.hour,head->end.min);
		head=head->next;
	}
}

void fun()
{
	int i;
	int j;
	for(i=0;i<2000;i++)
	for(j=0;j<5000;j++);
	system("busybox clear");
}

int check_time(DATA* q, struct tm* p)
{
	int start=q->start.hour*60+q->start.min;
	int end=q->end.hour*60+q->end.min;
	int now=p->tm_hour*60+p->tm_min;
	int free_start=end;
	int free_end=q->next->start.hour*60+q->next->start.min;
	if(start<=now&&now<end)
	{
		printf("%s\n",q->str);return 0;
	}
	if(free_start<=now&&now<free_end)
	{
		printf("课间休息\n");
		return 0;
	}
	return 1;
}

void find_time(DATA* head)
{
	DATA* temp;
	time_t timep;
	struct tm* p;
	for(;;)
	{
		time(&timep);
		p=localtime(&timep);
		printf("当前时间:%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);
		for(temp=head; temp->next!=NULL&&check_time(temp,p); temp=temp->next);
		if(temp->next==NULL)printf("%s\n",temp->str);
		fun();
	}
}

int main(int argc,char* argv[])
{
	DATA* head;
	if(fopen("time.data","r")==NULL)
	{
		work_place(argv[0]);
	}
	head=read_data();
	//put_data(head);
	find_time(head);
	return 0;
}
