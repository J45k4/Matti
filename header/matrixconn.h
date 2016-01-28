#ifndef MATRIXCONNECTION_H
#define MATRIXCONNECTION_H

#include <iostream>
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

using namespace std;

class MatrixConnection {
    	vector<std::thread> workerThreads;
	
	struct addrinfo host_info;
	struct addrinfo *host_info_list;
	
	struct sockaddr_in serv_addr;
  	struct hostent *server;
	
	int socketfd;
	
	string ip;
	string port;
	
	bool connected;
	
	public:
	MatrixConnection();
	MatrixConnection(string ip, string port);
	
	int Init();
	
	void Connect();
	void Connect(string ip, string port);
	
	ssize_t Send(char *buffer);
	char *Recv();
	
	bool Connected();
    
    string Ip();

};
            
#endif // MATRIXCONNECTION_H