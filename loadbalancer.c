#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {

	int socket_desc,c_sock,read_size,serversocket1,serversocket2;
	struct sockaddr_in,loadbalancer,client,server1.server2;
	char c_message[2000];
	
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket==-1){
		printf("cant create socket");
	}
	puts("loadbalancer socket created");
	
	loadbalancer.sin_family = AF_INET;
	loadbalancer.sin_addr=INADDR_ANY;
	loadbalancer.sin_port=htons(1000);
	
	if(bind(socket_desc,(struct sockaddr *)&loadbalancer,sizeof(loadbalancer))<0) {
	return 1;
	}

	puts("bind done");
	
	listen(socket_desc,3);

	puts("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);

	c_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(c_sock<0) {
	perror("accept failed");
	return 1;
	}

	puts("connection accepted")'
	
	read_size=recv(c_sock,c_message,2000,0);
	 

	if(strcmp(c_message,"book")==0) {
		 
		serversocket1=socket(AF_INET,SOCK_STREAM,0);
		server1.sin_family=AF_INET;
		server1.sin_addr.s_addr = inet_addr("192.168.120.128");
		if(connect(serversocket1,(struct sockaddr *)&server1,sizeof(server1))<0) {
		perror("fail to connect to loadbalancer");
		return 1 ;
		}

		if(send(serversocket1,c_message,strlen(c_message),0)<0){

		puts("fail to send");
		return 1;
		close(serversocket1);
		}else if(strcmp(c_message,"pen")==0) {
		
		serversocket2=socket(AF_INET,SOCK_STREAM,0);
		server2.sin_family=AF_INET;
		server2.sin_addr.s_addr = inet_addr("192.168.120.129");
		if(connect(serversocket1,(struct sockaddr *)&server2,sizeof(server2))<0) {
		perror("fail to connect to loadbalancer");
		return 1 ;
		}
		
		if(send(serversocket2,c_message,strlen(c_message),0)<0){

		puts("fail to send");
		return 1;
		close(serversocket2);

		}else{
		printf("error !!  the message did not redirected to any server");
		}
}
		
		


