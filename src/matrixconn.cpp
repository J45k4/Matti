#include "matrixconn.h"

MatrixConnection::MatrixConnection() {
	Init();
}

MatrixConnection::MatrixConnection(string ip, string port) {
	Init();
	Connect(ip, port);
}

int MatrixConnection::Init() {
	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  	host_info.ai_socktype = SOCK_STREAM;
	 return 0;	  
}
	
void MatrixConnection::Connect() {
	int status;
	status = getaddrinfo(ip.c_str(), port.c_str(), &host_info, &host_info_list);
	if (status == 0) {
		socketfd;
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
		host_info_list->ai_protocol);
		if (socketfd != -1) {
			status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
			if (status != -1) {
				connected = true;
			} else cout << "Failed when connecting socket" <<endl;
		} else cout << "Failed when creating socket" <<endl;
	} else {
		cout << "Failed to get address" <<endl;
	}
}

void MatrixConnection::Connect(string ip, string port) {
	this->ip = ip;
	this->port = port;
	Connect();
}
	
ssize_t MatrixConnection::Send(char *buffer) {
	ssize_t bytes_sent;
	int len = strlen(buffer);
	bytes_sent = send(socketfd, buffer, len, 0);
}

char *MatrixConnection::Recv() {
	char *buffer = new char[128];
    int n;
    bzero(buffer,128);
    n = read(socketfd,buffer,128);
    if (n < 0) {
        cout << "Error when reading from socket" <<endl;
    } 
    return buffer;
}

bool MatrixConnection::Connected() {
	return connected;
}

string MatrixConnection::Ip() {
    return ip;
}
