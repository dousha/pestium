#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "connection.h"
#include "logger.h"

bool connection_start(uint16_t port){
	fd_set master;
	fd_set read_fds;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int fdmax = 0;
	int listener = 0;
	int newfd = 0;
	char buffer[1024];
	ssize_t nbytes;
	int yes = 1;
	int i, j;
	FD_ZERO(&master);
	FD_ZERO(&read_fds);

	if((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		warn("connection", "socket() failed.");
		return false;
	}
	if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1){
		warn("connection", "setsockopt() failed.");
		return false;
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	memset(&(server.sin_zero), 0, 8);
	if(bind(listener, (struct sockaddr*) &server, sizeof(server)) == -1){
		warn("connection", "bind() failed.");
		return false;
	}
	if(listen(listener, 10) == -1){
		warn("connection", "listen() failed.");
		return false;
	}
	FD_SET(listener, &master);
	fdmax = listener;

	for(;;){
		read_fds = master;
		if(select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1){
			warn("connection", "wtf select() failed???");
			return false;
		}
		for(i = 0; i <= fdmax; i++){
			if(FD_ISSET(i, &read_fds)){
				if(i == listener){
					int addrlen = sizeof(client);
					if((newfd = accept(listener, (struct sockaddr*) &client, (socklen_t*) &addrlen)) == -1){
						warn("connection", "accept() failed");
						// doesn't matter
					}else{
						FD_SET(newfd, &master);
						if(newfd > fdmax){
							fdmax = newfd;
						}
						printf("|connection> new connection from %s on socket %d\n", inet_ntoa(client.sin_addr), newfd);
					}
				}else{
					if((nbytes = recv(i, buffer, sizeof(buffer), 0)) <= 0){
						// notice that for this part
						// sockets are closed lazily. unless new data come in, closed connections won't be actually
						// freed by system.
						if(nbytes == 0){
							printf("|connection> socket %d closed.\n", i);
						}else{
							printf("!connection> unexpected data from %d, closing\n", i);
						}
						close(i);
						FD_CLR(i, &master);
					}else{
						// all your datum are belong to this part
						// about packet formats, see docs/packets.md
						// broadcast
						for(j = 0; j <= fdmax; j++){
							if(FD_ISSET(j, &master)){
								if(j != listener && j != i){
									if(send(j, buffer, (size_t) nbytes, 0) == -1){
										warn("connection", "send() failed");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}