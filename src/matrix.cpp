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
#include <sys/ioctl.h>


int keepalive_enabled = 1;
int keepalive_time = 50;
int keepalive_count = 3;
int keepalive_interval = 3;

socklen_t enabled_len = sizeof(keepalive_enabled);
socklen_t time_len = sizeof(keepalive_time);
socklen_t count_len = sizeof(keepalive_count);
socklen_t internal_len = sizeof(keepalive_interval);


Matrix::Matrix(const char *ip, const char* port, int numOfCons, int numOfCpus, int id) {
	this->ip = ip;
	this->port = port;
	this->numOfCons = numOfCons;
	this->numOfCpus = numOfCpus;
	videoConnections = new unsigned int[numOfCons];
	kwmConnections = new unsigned int[numOfCpus];
	this->id = id;
}
	
Matrix::~Matrix() {
	close(socketfd);
}

void Matrix::setNonblocking()
{
    int flags;

    /* If they have O_NONBLOCK, use the Posix way to do it */
#if defined(O_NONBLOCK)
    /* Fixme: O_NONBLOCK is defined but broken on SunOS 4.1.x and AIX 3.2.5. */
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    // /* Otherwise, use the old way of doing it */
    // flags = 1;
    // return ioctl(fd, FIOBIO, &flags);
#endif
} 

void Matrix::sendBuffer(unsigned char *buffer) {
    Check();
	if (!Connected()) Connect();
	int len = sizeof(buffer);
	ssize_t bytes_sent;
	bytes_sent = send(socketfd, buffer, len, 0);
	time(&lastPacket);
}

unsigned int *Matrix::getVideoConnections() {
	return videoConnections;
}
	
unsigned int *Matrix::getKwmConnections() {
	return kwmConnections;
}
	
void Matrix::setVideo(unsigned char con, unsigned char cpu) {
	unsigned char buffer[6] = {0x2, VIDEO_SIGNAL, 128 + con, 128 + cpu, 0x3};
	sendBuffer(buffer);
}

void Matrix::conOutputOff(unsigned char con) {
	unsigned char buffer[4] = {0x2, VIDEO_OFF, 128 + con, 0x3};
	sendBuffer(buffer);
}

void Matrix::setAllVideo(unsigned char *con, unsigned char *cpu) {

}

void Matrix::turnOffAllConPorts() {
	unsigned char buffer[3] = {0x2, ALL_VIDEO_OFF, 0x3};
	sendBuffer(buffer);
}
	
void Matrix::setKwm(unsigned char con, unsigned char cpu) {
	unsigned char buffer[6] = {0x2, KWM_SIGNAL, 128 + cpu, 128 + con, 0x3};
	sendBuffer(buffer);	
}

void Matrix::kwmOutputOff(unsigned char cpu) {
	unsigned char buffer[4] = {0x2, KWM_OFF, 128 + cpu, 0x3};
	sendBuffer(buffer);
}

void Matrix::setAllKwm(unsigned char *cpu, unsigned char *con) {

}

void Matrix::turnOffAllCpuPorts() {
	unsigned char buffer[3] = {0x2, ALL_KWM_OFF, 0x3};
	sendBuffer(buffer);
}

void Matrix::establishBidirectionalConnection(unsigned char con, unsigned char cpu) {
	unsigned char buffer[5] = {0x2, ESTABLISH_BIDI_CONNECTION, 128 + con, 128 + cpu, 0x3};
	sendBuffer(buffer);
}

void Matrix::disconnectCon(unsigned char con) {
	unsigned char buffer[4] = { 0x2, DISCONNECT_CON, 128 + con, 0x3 };
	sendBuffer(buffer);
}

void Matrix::setMatrixCompleteSetup(unsigned char *values) {

}

void Matrix::reset() {
	unsigned char buffer[3] = { 0x2, RESET_MATRIX, 0x3 };
	sendBuffer(buffer);
}
	
void Matrix::requestAllStates(function<void(AllConnections *allConnections)> callback) {
	requestAllStatesCallbacks.push_back(callback);
	time_t timeNow;
	time(&timeNow);
	if (difftime(timeNow, lastRequestAllStates) > requestAllStatesTimeout) {
		unsigned char buffer[3] = {0x2, REPORT_MATRIX, 0x3};
		sendBuffer(buffer);
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
	
void Matrix::Connect() {
	int status;
  	struct addrinfo host_info;
	struct addrinfo *host_info_list;
   	//int socketfd = -1;  
     
   	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
	host_info.ai_socktype = SOCK_STREAM;
     
	status = getaddrinfo(ip.c_str(), port.c_str(), &host_info, &host_info_list);
	if (status == 0) {
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol); 
		setsockopt(socketfd, SOL_SOCKET, SO_KEEPALIVE, &keepalive_enabled, enabled_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPIDLE, &keepalive_time, time_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPCNT, &keepalive_count, count_len);
		setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPINTVL, &keepalive_interval, internal_len);
		status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
		setNonblocking();
		connected = true;
	}		
}

void Matrix::Disconnect() {
	connected = false;
	close(socketfd);
}
	
bool Matrix::Connected() {
	return connected;
}

void Matrix::refresh() {
	unsigned char readBuffer[256];
	int bytes = read(socketfd, &readBuffer, sizeof(readBuffer));
	if (bytes > 0) {
		if (readBuffer[0] != 0x2) return;
		switch(readBuffer[1]) {
			case VIDEO_SIGNAL:
				videoConnections[readBuffer[2] - 128] = readBuffer[3] - 128;
				break;
			case VIDEO_OFF:
				videoConnections[readBuffer[2] - 128] = 0;
				break;
			case MULTI_VIDEO_SIGNAL:
				break;
			case ALL_VIDEO_OFF:
				break;
			case KWM_SIGNAL:
				kwmConnections[readBuffer[2] - 128]= readBuffer[3] - 128;
				break;
			case KWM_OFF:
				kwmConnections[readBuffer[2] - 128] = 0;
				break;
			case MULTI_KWM_SIGNAL:
				break;
			case ALL_KWM_OFF:
				break;
			case ESTABLISH_BIDI_CONNECTION:
				videoConnections[readBuffer[2] - 128] = readBuffer[3] - 128;
				kwmConnections[readBuffer[3] - 128] = readBuffer[2] - 128;
				break;
			case DISCONNECT_CON:
				break;
			case SET_COMPLETE:
				break;
			case RESET_MATRIX:
				break;
			case REPORT_MATRIX:
				for (int i = 0; i < 16;i++) {
					videoConnections[i] = readBuffer[i+2]-128;
				}
				for (int i = 0; i < 16; i++) {
					kwmConnections[i] = readBuffer[i+18]-128;
				}
				emptyRequestAllStatesQueue();
				time(&lastRequestAllStates);
				break;
		}
	}
	time_t timeNow;
	time(&timeNow);
	if (difftime(timeNow, lastRequestAllStates) < requestAllStatesTimeout) {
		emptyRequestAllStatesQueue();
	}
}

void Matrix::emptyRequestAllStatesQueue() {
	while (!requestAllStatesCallbacks.empty())
	{
		AllConnections * allConnections = new AllConnections();
		for (int i = 0; i < numOfCons; i++) {
			VideoConnection *videoConnection = allConnections->add_videoconnections();
			videoConnection->matrixId 
		}
		for (int i = 0; i < numOfCpus; i++) {
			allConnections->add_kwmconnections(kwmConnections[i]);
		}
		requestAllStatesCallbacks.front()(allConnections);
		requestAllStatesCallbacks.pop_front();
	}	
}

string Matrix::getIp() {
	return ip;
}

string Matrix::getPort() {
	return port;
}

int Matrix::getNumOfCons() {
	return numOfCons;
}

int Matrix::getNumOfCpus() {
	return numOfCpus;
}