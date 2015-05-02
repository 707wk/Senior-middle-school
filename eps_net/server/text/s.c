#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>

#define MAX_SUM 10000

typedef struct user
{
	int user_id;
	int passwd;
	int num;
	char answer[MAX_SUM];
}USER;

#define SERVPORT 1707 /*server port number */
#define BACKLOG 10 /*max link*/
#define MAX_MESG_LEN 1024  /*max message len*/

#define HSUI 1 /*have same user id*/
#define NFOPE 2 /*not find or password error*/
#define LOADOK 0 /*user is ok and password is ok*/

#define SAVE_SUCCESS ""

int main()
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
	return 0;
}
