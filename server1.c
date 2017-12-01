#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {

	int socket_desc,c_sock,c,r_size;
	struct sockaddr_in server,client;
	char c_message[2000];

	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1){
		printf("cant create socket");
	}
	
	puts("socket created");
		
	server.sin_family = af_inet;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_[ort = htons(3000);

	if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0){
	perror("fail to bind the socket to server");
	return 1;
	}

	puts("bind done");
	
	listen(socket_desc,3);
	
	put("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);

	client_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(client_sock<0){

	perror("accept failed");
	return 1;
	}

	puts("connection accepted");

	r_size=recv(c_sock,c_message,2000,0);

	printf("%s",c_message);
}	