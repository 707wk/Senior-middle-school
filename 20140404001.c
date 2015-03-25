/*----------------------------------------------
Text: 随机走向
File: D:\Win-TC\projects\temp.c
Date: 2014-4-4 13:24:53
Author: 1174843091@qq.com
Example:
======================
|					|
|					|
|					|
|					|
|					|
|					|
|					|
|  	ABCDEF		|
|   	ONMLGH   	|
|   	PQRKJI   	|
======================
----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define HEIGHT 15
#define WIDE 70

struct node
{
	int x;
	int y;
	struct node* next;
};

void getpos(HANDLE hOut,COORD *pos)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( hOut , &info );
	*pos = info.dwCursorPosition;
}
void gotopos(HANDLE hOut,COORD pos)
{
	SetConsoleCursorPosition(hOut, pos);
}

void start_map(HANDLE hOut,COORD pos)
{
	int i;
	int j;
	pos.X=0;
	pos.Y=0;
	gotopos(hOut,pos);
	for(i=0; i<HEIGHT+2; i++)
	{
		for(j=0; j<WIDE+2; j++)
		{
			if(i==0||i==HEIGHT+1)
			{
				printf("=");
			}
			else if(j==0||j==WIDE+1)
			{
				printf("|");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	pos.X=1;
	pos.Y=1;
	gotopos(hOut,pos);
}

int ckech_way(struct node dot,struct node* head)
{
	while(head!=NULL)
	{
		if(dot.x==head->x&&dot.y==head->y)
		{
			return 1;
		}
		head=head->next;
	}
	return 0;
}

int no_way(struct node dot,struct node* head)
{
	int temp=0;
	while(head!=NULL)
	{
		if(dot.x==head->x+1&&dot.y==head->y) 	//左边
		{
			temp++;
		}
		else if(dot.x==head->x-1&&dot.y==head->y)//右边
		{
			temp++;
		}
		else if(dot.x==head->x&&dot.y==head->y+1)//上面
		{
			temp++;
		}
		else if(dot.x==head->x&&dot.y==head->y-1)//下面
		{
			temp++;
		}
		head=head->next;
	}
	if(dot.x==1||dot.x==WIDE)
	{
		temp++;
	}
	if(dot.y==1||dot.y==HEIGHT)
	{
		temp++;
	}
	if(temp==4)
	{
		return 1;
	}
	return 0;
}

void free_node(struct node* head)
{
	struct node* p;
	while(head!=NULL)
	{
		p=head->next;
		free(head);
		head=p;
	}
}

int main()
{
	int i;
	int flage;
	char c;
	HANDLE hOut;
	COORD pos;
	struct node dot;
	struct node* head;
	struct node* p;
	struct node* q;
_next:
	c='\2';
	srand(time(NULL));
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	head=p=q=(struct node*)malloc(sizeof(struct node));
	p->x=dot.x=1+rand()%(WIDE);
	p->y=dot.y=1+rand()%(HEIGHT);
	p->next=NULL;
	dot.next=NULL;
	start_map(hOut,pos);
	pos.X=dot.x;
	pos.Y=dot.y;
	gotopos(hOut,pos);
	printf("%c\b",c++);
	for(; c<='Z';)
	{
		switch(flage=rand()%4)
		{
		case 0:
			dot.y--;
			break;
		case 1:
			dot.y++;
			break;
		case 2:
			dot.x--;
			break;
		case 3:
			dot.x++;
			break;
		}
		if(dot.x<1||dot.x>WIDE||dot.y<1||dot.y>HEIGHT||ckech_way(dot,head))
		{
			switch(flage)
			{
			case 0:
				dot.y++;
				break;
			case 1:
				dot.y--;
				break;
			case 2:
				dot.x++;
				break;
			case 3:
				dot.x--;
				break;
			}
		}
		else
		{
			q=p;
			p=(struct node*)malloc(sizeof(struct node));
			p->x=pos.X=dot.x;
			p->y=pos.Y=dot.y;
			q->next=p;
			p->next=NULL;
			gotopos(hOut,pos);
			switch(flage)
			{
				case 0:
				//printf("%c\b",30);
				printf("%c\b",24);
				break;
				case 1:
				//printf("%c\b",31);
				printf("%c\b",25);
				break;
				case 2:
				//printf("%c\b",17);
				printf("%c\b",27);
				break;
				case 3:
				//printf("%c\b",16);
				printf("%c\b",26);
				break;
				
			}
			//printf("%c\b",c++);
			if(no_way(dot,head))
			{
				break;
			}
			Sleep(100);
		}
	}
	free_node(head);
	getchar();
	goto _next;
	getchar();
	return 0;
}
