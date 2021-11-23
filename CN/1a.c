#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    int cs,ns,fd,n;
    char msg[255];
    int bufferSize = 1024;
    char *buffer = malloc(bufferSize);
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(15000);
    address.sin_family = AF_INET;
    cs = socket(AF_INET,SOCK_STREAM,0);
    bind(cs,(struct sockaddr *)&address,sizeof(address));
    listen(cs,3);
    ns = accept(cs,(struct sockaddr *)NULL,NULL);
    recv(ns,msg,255,0);
    fd = open(msg,O_RDONLY);
    n = read(fd,buffer,bufferSize);
    send(ns,buffer,n,0);
    close(ns);
    return 0;
}