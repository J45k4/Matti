#include "matrix.h"
#include "cmdconst.h"
#include <vector>
#include <netinet/tcp.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <string>
#include <thread>
#include <list>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


int keepalive_enabled = 1;
int keepalive_time = 50;
int keepalive_count = 3;
int keepalive_interval = 3;

socklen_t enabled_len = sizeof(keepalive_enabled);
socklen_t time_len = sizeof(keepalive_time);
socklen_t count_len = sizeof(keepalive_count);
socklen_t internal_len = sizeof(keepalive_interval);


Matrix::Matrix(const char *ip, const char* port) {
	this->ip = ip;
	this->port = port;
}
	
Matrix::~Matrix() {
	close(socketfd);
}

unsigned int *Matrix::getVideoConnections() {
	return videoConnections;
}
	
unsigned int *Matrix::getKwmConnections() {
	return kwmConnections;
}
	
void Matrix::setVideo(int con, int cpu) {
	char buffer[6] = {0x2, 71, 128 + con, 128 + cpu, 0x3};
	int len = strlen(buffer);
	ssize_t bytes_sent;
	bytes_sent = send(socketfd, buffer, len, 0);
	time(&lastPacket);	
}
	
void Matrix::setKwm(int con, int cpu) {
	
}
	
void Matrix::requestAllStates() {
	Check();
	char buffer[3] = {0x2, 0x53, 0x3};
	send(socketfd, buffer, 3, 0);
	unsigned char readbuffer[1024];
	int bytes = read(socketfd, &readbuffer, sizeof(readbuffer));
	printf(" %d \n", readbuffer[2]);
	for (int i = 0; i < 16;i++) {
		videoConnections[i] = readbuffer[i+2]-128;
	}
	for (int i = 0; i < 16; i++) {
		kwmConnections[i] = readbuffer[i+18]-128;
	}
	
	for (int i = 0; i < 16; i++) {
		printf(" %d ", videoConnections[i]);
	}
}
	
void Matrix::Check() {
	time_t timeNow;
	time(&timeNow);
	if (difftime(timeNow, lastPacket) > timeout) {
		Disconnect();
		Connect();
	}
}
	
void Matrix::setTimeout() {

}
	
int Matrix::Connect() {
	int status;
  	struct addrinfo host_info;
	struct addrinfo *host_info_list;
   	//int socketfd = -1;  
     
   	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
	host_info.ai_socktype = SOCK_STREAM;
     
	status = getaddrinfo(ip.c_str(), port.c_str(), &host_info, &host_info_list);
	if (status == 0) {
		cout << "Creating socketfd" <<endl;
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol); 
		setsockopt(socketfd, SOL_SOCKET, SO_KEEPALIVE, &keepalive_enabled, enabled_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPIDLE, &keepalive_time, time_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPCNT, &keepalive_count, count_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPINTVL, &keepalive_interval, internal_len);
		status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
		connected = true;
	}

	return socketfd;		
}

void Matrix::Disconnect() {
	connected = false;
	close(socketfd);
}
	
bool Matrix::Connected() {
	return connected;
}
	