#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>


int main(){

	int sock;
	struct sockaddr_in server;
	char message[2000];
	
	sock=socket(AF_INET,SOCK_STREAM,0)'
	if(sock==-1){
		printf("could not create socket")'
	}
	puts("socket created");
	server.sin_Addr.sin_addr=inet_addr("192.168.235.129);
	server.sin_family=AF_INET;
	server.sin_port=htons(1000);
	
	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){
	perror("fail to connect to loadbalancer");
	return 1;

	print("enter your message:");
	scanf("%s",message);
		if(send(sock,message,strlen(message),0)<0){
	puts("fail to send");
	return 1;
	}
	close(sock);
	
	return 0;
	}
