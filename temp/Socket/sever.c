#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//#include "types.h"
//#include <netinet/in.h>
//#include <sys/socket.h>
#include <sys/wait.h>
#define SERVPORT 3333 /*�����������˿ں� */
#define BACKLOG 10 /* ���ͬʱ���������� */
main()
{
    int sockfd,client_fd; /*sockfd������socket��client_fd�����ݴ���socket */
    struct sockaddr_in my_addr; /* ������ַ��Ϣ */
    struct sockaddr_in remote_addr; /* �ͻ��˵�ַ��Ϣ */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror( "socket��������");
        exit(1);
    }
    �� 2 ҳ
    C_Socket.txt
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero( &(my_addr.sin_zero),8);
    if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror( "bind����");
        exit(1);
    }
    if (listen(sockfd, BACKLOG) == -1)
    {
        perror( "listen����");
        exit(1);
    }
    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        if ((client_fd = accept(sockfd, (struct sockaddr *) &remote_addr, &sin_size)) == -1)
        {
            perror( "accept����");
            continue;
        }
        printf( "received a connection from %s\n", inet_ntoa(remote_addr.sin_addr));
        if (!fork())   /* �ӽ��̴���� */
        {
            if (send(client_fd, "Hello, you are connected!\n", 26, 0) == -1)
                perror( "send����");
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }
}
}
