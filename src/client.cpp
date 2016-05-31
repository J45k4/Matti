#include "client.h"

Client::Client(int socketfd) {
	this->socketfd = socketfd;
}

Client::~Client() {
	
}


int Client::getSocketFd() {
	return socketfd;
}