#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define SERVPORT 3333
#define MAXDATASIZE 100 /*每次最大数据传输量 */
main(int argc, char *argv[])
{
    int sockfd, recvbytes;
    char buf[MAXDATASIZE];
    struct hostent *host;
    struct sockaddr_in serv_addr;
    if (argc < 2)
    {
        fprintf(stderr,"Please enter the server's hostname!\n");
        exit(1);
    }
    if((host=gethostbyname(argv[1]))==NULL)
    {
        herror("gethostbyname出错！");
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket创建出错！");
        exit(1);
    }
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)host- >h_addr);
    bzero( &(serv_addr.sin_zero),8);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, \
                sizeof(struct sockaddr)) == -1)
    {
        perror("connect出错！");
        exit(1);
    }
    if ((recvbytes=recv(sockfd, buf, MAXDATASIZE, 0)) ==-1)
    {
        perror("recv出错！");
        exit(1);
    }
    第 3 页
    C_Socket.txt
    buf[recvbytes] = '\0';
    printf( "Received: %s",buf);
    close(sockfd);
}