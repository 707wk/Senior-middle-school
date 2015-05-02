#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define _LINUX_
#ifdef _LINUX_
	#include <unistd.h>
	#include <errno.h>
	#include "include/getch.h"
#endif

#define _NETWORK_
#ifdef _NETWORK_
	#include <sys/types.h>
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include <sys/wait.h>
	#include <arpa/inet.h>
#endif

#include "include/checkdate.h"
#include "include/option.h"

void clear_type()//clean tty
{
	system("busybox clear");
}

void work_place(char* str)//change work place
{
	char* temp;
	char* q;
	temp=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp,str);
	q=temp+strlen(str);
	while(*q!='/')q--;
	*q='\0';
	chdir(temp);
}

int ELFHash( char str[] )//str tar
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

int read_data_sum()//check text data sum
{
	int sum;
	FILE* fpin;
	fpin=fopen(files_name,"r");
	if(fpin==NULL)
	{
		printf("error	:	files %s can not open !\n",files_name);
		exit(1);
	}
printf("read data num from %s ...\n",files_name);
	for(sum=0;!feof(fpin);)
	{
		if('^'==fgetc(fpin))sum++;
	}
	fclose(fpin);
printf("data num are %d \n",sum);
	return sum;
}

int read_user_sum()//check user sum
{
	int sum;
	FILE* fpin;
	fpin=fopen(user_name,"r");
	if(fpin==NULL)
	{
		printf("error	:	files %s can not open !\n",user_name);
		exit(1);
	}
printf("read user num from %s ...\n",files_name);
	for(sum=0;!feof(fpin);)
	{
		if('\n'==fgetc(fpin))sum++;
	}
	fclose(fpin);
printf("user num are %d \n",sum);
	return sum;
}

int find_user_id(USER* head_user,int len,USER user_new)//find user
{
	int left=0;
	int right=len-1;
	int mid=(left+right)>>1;
	while(left<=right)
	{
		if(head_user[mid].user_id<user_new.user_id)left=mid+1;
		else if(head_user[mid].user_id>user_new.user_id)right=mid-1;
		else return mid;
		mid=(left+right)>>1;
	}
	return -1;
}

int cut_user_data(USER* head_user,int user_sum,USER user_new)//add user data
{
	int i;
	if(find_user_id(head_user,user_sum,user_new)!=-1)return 1;
	for(i=user_sum-1;user_new.user_id<head_user[i].user_id&&i>=0;i--)
		head_user[i+1]=head_user[i];
	head_user[i+1]=user_new;
	return 0;
}

int del_user_data(USER* head_user,int user_sum,USER user_new)//delete user data
{
	int j;
	int i=find_user_id(head_user,user_sum,user_new);
	if(i==-1)return 1;
	for(j=i;j<user_sum;j++)
		head_user[j]=head_user[j+1];
	return 0;
}

int read_data(DATA* head,int data_sum)//read text data
{
	int i;
	int sum;
	char temp;
	FILE* fpin;
	DATA* p=head;
	fpin=fopen(files_name,"r");
	if(fpin==NULL)
	{
		printf("error	:	files %s can not open !\n",files_name);
		exit(1);
	}
printf("read data from %s ...\n",files_name);
	for(sum=0;!feof(fpin);sum++)
	{
		for(i=0;!feof(fpin)&&(temp=fgetc(fpin))!='^'&&sum<=data_sum;i++)
		{
			p->text[i]=temp;
		}
		p->text[i]='\0';
		if(feof(fpin))
		{
			p->text[0]='\0';
			break;
		}
		p->ans=fgetc(fpin);
		fgetc(fpin);
		p++;
	}
	fclose(fpin);
printf("read data from %s is ok\n",files_name);
	return sum;
}

void read_user_data(USER* head,int user_sum,int data_sum)//read user data
{
	FILE* fpin;
printf("read data from %s ...\n",user_name);
	fpin=fopen(user_name,"r");
	if(fpin==NULL)
	{
		printf("error	:	files %s can not open !\n",user_name);
		exit(1);
	}
	for(;!feof(fpin);head++)
	{
		fscanf(fpin,"%d %d %d %s\n",&head->user_id,&head->passwd,&head->num,head->answer);
	}
	fclose(fpin);
printf("read data from %s is ok\n",user_name);
}

void new_start()//creat option files
{
	int sum;
	FILE* fpio;
	fpio=fopen(files_name,"r");
	if(fpio==NULL)
	{
		printf("error	:	files %s can not open !\n",files_name);
		exit(1);
	}
	for(sum=0;!feof(fpio);)
	{
		if(fgetc(fpio)=='^')sum++;
	}
	fclose(fpio);
	if( ( fpio=fopen( option_name , "w" ) ) == NULL )
	{
		printf("error	:	files %s can not save !\n",option_name);
		exit( 1 ) ;
	}
	fprintf(fpio,"password = %d",6796286);
	fclose(fpio);
}

void start_pg(char* argv[],DATA* head_data,int data_sum,USER* head_user,int user_sum)//read data
{
	if(fopen(files_name,"r")==NULL)
	{
		work_place(argv[0]);
	}
	if(fopen(option_name,"r")==NULL)
	{
		new_start();
	}
	if(fopen(user_name,"r")==NULL)
	{
		printf("error	:	files %s can not open !\n",user_name);
		exit(1);
	}
	read_data(head_data,data_sum);
	read_user_data(head_user,user_sum,data_sum);
}

viod save_user_data(USER* head_user,int user_sum)//save user data
{
	FILE* fpout;
	fpout=fopen(user_name,"w");
	if(fpout==NULL)
	{
		printf("error	: files %s can not save !\n",user_name);
		exit(0);
	}
	while(--user_sum)
	{
		fprintf(fp,"%d %d %d %s\n",head_user->user_id,head_user->password,head_user->num,head_user->answer);
		head_user++;
	}
	fclose(fpin);
}

int rw_option( char rw , int nb , int n )//read and write option files
{
	int nu[2] ;
	FILE *fp ;
	if( ( fp=fopen( option_name , "r" ) ) == NULL ||n>=2)
	{
		fclose( fp ) ;
		exit(0);
	}
	fscanf( fp , "password = %d" , &nu[0] ) ;
	fclose( fp ) ;
	switch( rw )
	{
	case 'r':
		if( nu[n] < 1 )return 1 ;
		return nu[n] ;
	case 'w':
		if( ( fp=fopen( option_name , "w" ) ) == NULL )
		{
			fclose( fp ) ;
			exit( 0 ) ;
		}
		if( nb < 1 )nu[n] =1 ;
		else nu[n] =nb ;
		fprintf( fp , "password = %d" , nu[0] ) ;
		fclose( fp ) ;
		return 1 ;
	}
	return 0 ;
}

void check_load()//check password
{
	int i=0;
	char a[200]={0};
	char b;
	printf("please input the password : ");
	while((b=getch())=='\r');
	while(b!='\r')
	{
		if(b!=127)
		{
			printf("*");
			a[i]=b;
			i++;
		}
		else if(i>=0)
		{
			a[i]=0;
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		b=getch();
		a[i]=0;
	}
	while(ELFHash(a)!=rw_option('r',0,0))
	{
		clear_type();
		printf("error : please input the password : ");
		i=0;
		while((b=getch())=='\r');
		while(b!='\r')
		{
			if(b!=127)
			{
				printf("*");
				a[i]=b;
				i++;
			}
			else if(i>=0)
			{
				a[i]=0;
				if(i>0)
				{
					i--;
					printf("\b \b");
				}
			}
			b=getch();
		}
		a[i]=0;
	}
	clear_type();
}

viod user_new_option(USER* user_data)//start new user answer
{
	char* str=user->answer;
	for(;str<user->answer+MAX_SUM-1;str++)
	{
		*str='0';
	}
	*str='\0';
}

void net_server()
{
	int sin_size;
	int sockfd;
	int client_fd; /*sockfd:监听socket;client_fd:数据传输socket */
	char client_mesg[MAX_MESG_LEN];
	struct sockaddr_in my_addr; /* load address message */
	struct sockaddr_in remote_addr; /* client address message */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror( "make socket error !\n"); 
		exit(1);
	}
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(SERVPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero( &(my_addr.sin_zero),8);
	if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1)
	{
		perror( "bind error !\n");
		exit(1);
	}
	if (listen(sockfd, BACKLOG) == -1)
	{
		perror( "listen error !\n");
		exit(1);
	}
	printf("start server...\n");
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		if ((client_fd = accept(sockfd, (struct sockaddr *) &remote_addr, (socklen_t *)&sin_size)) == -1)
		{
			perror( "accept error !\n");
			continue;
		}
		printf( "received a connection from %s\n", inet_ntoa(remote_addr.sin_addr));
		if (!fork())
		{
			/* 子进程代码段 */
			if(recv(client_fd, client_mesg, MAX_MESG_LEN+1, 0) == -1)
			{
				close(client_fd);
				exit(0);
			}
			switch(*client_mesg)
			{
				case '0':/*注册*/
					_NEW_AGAIN_:;
					recv(client_fd, client_mesg, MAX_MESG_LEN, 0);
					sscanf(client_mesg,"%d %d",&user_data.user_id,&user_data.passwd);
					num=find_user_id(head_user,user_sum,user_data);
					if(num!=-1)
					{
						sprintf(client_mesg,"%d %d",NFOPE,NFOPE);
						send(client_fd, client_mesg, MAX_MESG_LEN, 0);
						goto _NEW_AGAIN_;
					}
					else
					{
						user_new_option(&user_data);
						cut_user_data(head_user,user_sum,user_data);
						sprintf(client_mesg,"%d %d",LOADOK,LOADOK);
						send(client_fd, client_mesg, MAX_MESG_LEN, 0);
					}
				break;
				case '1':/*登录*/
					_LOAD_AGAIN_:;
					recv(client_fd, client_mesg, MAX_MESG_LEN, 0);
					sscanf(client_mesg,"%d %d",&user_data.user_id,&user_data.passwd);
					num=find_user_id(head_user,user_sum,user_data);
					if(num==-1||head_user[num].passwd!=user_data.passwd)
					{
						sprintf(client_mesg,"%d %d",NFOPE,NFOPE);
						send(client_fd, client_mesg, MAX_MESG_LEN, 0);
						goto _LOAD_AGAIN_;
						//close(client_fd);
					}
					else
					{
						sprintf(client_mesg,"%d %d",LOADOK,MAX_SUM);
						send(client_fd, client_mesg, MAX_MESG_LEN, 0);
						sprintf(client_mesg,"%s",head_user[num].answer);
						send(client_fd, client_mesg, MAX_SUM, 0);
						close(client_fd);
					}
				break;
				case '2':/*存储*/
					recv(client_fd, client_mesg, MAX_MESG_LEN, 0);
					sscanf(client_mesg,"%d %s",&user_data.user_id,user_data.answer);
					num=find_user_id(head_user,user_sum,user_data);
					strcpy(head_user[num].answer,user_data.answer);
					send(client_fd, , MAX_SUM, 0);
					close(client_fd);
				break;
				default :
					close(client_fd);
				break;
			}
			/*
			if (send(client_fd, "Hello, you are connected!\n", MAX_MESG_LEN, 0) == -1)
			{
				perror( "send出错!");
			}
			*/
			//close(client_fd);
			exit(0);
		}
		close(client_fd);
	}
	printf("end server\n");
}

int main(int argc,char* argv[])
{
	//int i;
	int text_sum=read_data_sum();
	int user_sum=read_user_sum();
	DATA head_data[text_sum];
	USER head_user[MAX_USER];
	check_load();
	start_pg(argv,head_data,text_sum,head_user,user_sum);
	/*
	for(i=0;i<user_sum&&i<MAX_USER;i++)
	{
		printf("%d\n%d\n%s\n",head_user[i].user_id,head_user[i].passwd,head_user[i].answer);
		getchar();
	}
	*/
	net_server();
	return 0;
}
