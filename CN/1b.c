#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc,char **argv){
    int cs,n;
    char msg[255];
    int bufferSize = 1024;
    char *buffer = malloc(bufferSize);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(15000);
    inet_pton(AF_INET,argv[1],&address.sin_addr);
    cs = socket(AF_INET,SOCK_STREAM,0);
    connect(cs,(struct sockaddr*)&address,sizeof(address));
    printf("Enter filename: \n");
    scanf("%s",msg);
    send(cs,msg,255,0);
    while(recv(cs,buffer,bufferSize,0) > 0){
        printf("%s",buffer);
    }
    printf("/n EOF");
    close(cs);
    return 0;
}