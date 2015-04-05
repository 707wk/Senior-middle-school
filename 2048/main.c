/*
 * 2048 from c
 * Copyright 2014 wangk <1174843091@qq.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "getch.h"

#define LEN 4

void clear_screen()
{
	system("busybox clear");
}

void start_location(int num[LEN][LEN])
{
	int i;
	int j;
	for(i=0;i<LEN;i++)
	{
		for(j=0;j<LEN;j++)
		{
			num[i][j]=0;
		}
	}
	num[abs(rand())%LEN][abs(rand())%LEN]=(abs(rand())%2+1)*2;
	num[abs(rand())%LEN][abs(rand())%LEN]=(abs(rand())%2+1)*2;
}

void sum_num_up(int num[LEN][LEN])
{
	int i;
	int j;
	int p;
	int temp;
	for(j=0;j<LEN;j++)
	{
		for(p=i=0;i<LEN;i++)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[p][j]=temp;
				p++;
			}
		}
		for(i=0;i<LEN-1;i++)
		{
			if(num[i][j]==num[i+1][j])
			{
				num[i][j]=num[i][j]*2;
				num[i+1][j]=0;
				i++;
			}
		}
		for(p=i=0;i<LEN;i++)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[p][j]=temp;
				p++;
			}
		}
	}
}

void sum_num_down(int num[LEN][LEN])
{
	int i;
	int j;
	int p;
	int temp;
	for(j=0;j<LEN;j++)
	{
		for(p=i=LEN-1;i>=0;i--)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[p][j]=temp;
				p--;
			}
		}
		for(i=LEN-1;i>0;i--)
		{
			if(num[i][j]==num[i-1][j])
			{
				num[i][j]=num[i][j]*2;
				num[i-1][j]=0;
				i--;
			}
		}
		for(p=i=LEN-1;i>0;i--)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[p][j]=temp;
				p--;
			}
		}
	}
}

void sum_num_left(int num[LEN][LEN])
{
	int i;
	int j;
	int p;
	int temp;
	for(i=0;i<LEN;i++)
	{
		for(p=j=0;j<LEN;j++)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[i][p]=temp;
				p++;
			}
		}
		for(j=0;j<LEN-1;j++)
		{
			if(num[i][j]==num[i][j+1])
			{
				num[i][j]=num[i][j]*2;
				num[i][j+1]=0;
				j++;
			}
		}
		for(p=j=0;j<LEN;j++)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[i][p]=temp;
				p++;
			}
		}
	}
}

void sum_num_right(int num[LEN][LEN])
{
	int i;
	int j;
	int p;
	int temp;
	for(i=0;i<LEN;i++)
	{
		for(p=j=LEN-1;j>=0;j--)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[i][p]=temp;
				p--;
			}
		}
		for(j=LEN-1;j>0;j--)
		{
			if(num[i][j]==num[i][j-1])
			{
				num[i][j]=num[i][j]*2;
				num[i][j-1]=0;
				j--;
			}
		}
		for(p=j=LEN-1;j>0;j--)
		{
			if(num[i][j]!=0)
			{
				temp=num[i][j];
				num[i][j]=0;
				num[i][p]=temp;
				p--;
			}
		}
	}
}

void add_num(int num[LEN][LEN])
{
	int i=abs(rand()%LEN);
	int j=abs(rand()%LEN);
	while(num[i][j]!=0)
	{
		i=abs(rand()%LEN);
		j=abs(rand()%LEN);
	}
	num[i][j]=(abs(rand())%2+1)*2;
}

int check_game_end(int num[LEN][LEN])
{
	int i;
	int j;
	int sum=0;
	for(i=0;i<LEN;i++)
	{
		for(j=0;j<LEN;j++)
		{
			if(num[i][j])sum++;
		}
	}
	if(sum==LEN*LEN)
	{
		for(i=0;i<LEN;i++)
		{
			for(j=0;j<LEN-1;j++)
			{
				if(num[i][j]==num[i][j+1])
				{
					return 2;
				}
			}
		}
		for(j=0;j<LEN;j++)
		{
			for(i=0;i<LEN-1;i++)
			{
				if(num[i][j]==num[i+1][j])
				{
					return 2;
				}
			}
		}
		return 1;
	}
	return 0;
}

void put_bar(int num)
{
	while(num--)
	{
		printf("=");
	}
	printf("\n");
}

void put_location(int num[LEN][LEN])
{
	int i;
	int j;
	clear_screen();
	put_bar(6*LEN+1);
	for(i=0;i<LEN;i++)
	{
		printf("|");
		for(j=0;j<LEN;j++)
		{
			if(num[i][j])
			printf("%3d  |",num[i][j]);
			else printf("     |");
		}
		printf("\n");
		put_bar(6*LEN+1);
	}
}

int main(int argc,char* argv[])
{
	char ch;
	int num[LEN][LEN];
	srand((int)time(0));
	start_location(num);
	put_location(num);
	for(;;)
	{
		ch=getch();
		switch(ch)
		{
			case 'w':
				sum_num_up(num);
				goto _NEXT;
			break;
			case 's':
				sum_num_down(num);
				goto _NEXT;
			break;
			case 'a':
				sum_num_left(num);
				goto _NEXT;
			break;
			case 'd':
				sum_num_right(num);
				goto _NEXT;
			break;
		}
		if(0)
		{
			_NEXT:;
			switch(check_game_end(num))
			{
				case 0:
					add_num(num);
				break;
				case 1:
					goto _END;
				break;
				case 2:
				break;
			}
			put_location(num);
		}
	}
	_END:;
	//clear_screen();
	printf("game over!");
	return 0;
}
