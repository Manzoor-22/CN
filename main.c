#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in sa;
    int n, sockfd;
    char buff[100];
    
    // Creation of socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("\nSocket failed to open!");
        exit(0);
    } else{
        printf("\nSocket is opened!");
    }
    
    // Connection
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(80);
    
    if(connect(sockfd, (struct sockaddr*)&sa, sizeof(sa)) < 0){
        printf("\nConnection failed!");
        exit(0);
    } else{
        printf("\nConnection Established!");
    }
    
    // Recieve message
    n = read(sockfd, buff, sizeof(buff));
    
    if(n < 0){
        printf("\nMessage failed to recieve");
        exit(0);
    } else{
        printf("\n Message read : %s", buff);
    }

    return 0;
}
