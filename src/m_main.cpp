#include <stdio.h>

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

#include "../header/MattiRequest.pb.h"

using namespace std;

int keepalive_enabled = 1;
int keepalive_time = 50;
int keepalive_count = 3;
int keepalive_interval = 3;

socklen_t enabled_len = sizeof(keepalive_enabled);
socklen_t time_len = sizeof(keepalive_time);
socklen_t count_len = sizeof(keepalive_count);
socklen_t internal_len = sizeof(keepalive_interval);

			// setsockopt(socketfd, SOL_SOCKET, SO_KEEPALIVE, &keepalive_enabled, 1);
			// setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPIDLE, keepalive_time, &sizeof(keepalive_time));
			// setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPCNT, keepalive_count, &sizeof(keepalive_count));
			// setsockopt(socketfd, IPPROTO_TCP, TCP_KEEPINTVL, keepalive_interval, &sizeof(keepalive_interval));



class Matrix {
	int socketfd;
	string ip;
	string port;
	
	bool connected;
	
	float timeout = 50.0;

	time_t lastPacket;
	
public:
	Matrix(const char *ip, const char* port) {
		this->ip = ip;
		this->port = port;
	}
	
	~Matrix() {
		close(socketfd);
	}
	
	void setVideo(int con, int cpu) {
		char buffer[6] = {0x2, 71, 128 + con, 128 + cpu, 0x3};
		int len = strlen(buffer);
		ssize_t bytes_sent;
		bytes_sent = send(socketfd, buffer, len, 0);
		time(&lastPacket);	
	}
	
	void setKwm(int con, int cpu) {
		
	}
	
	void keepAlive() {
		
	}
	
	void check() {
		time_t timeNow;
		time(&timeNow);
		if (difftime(timeNow, lastPacket) > timeout) {
			Disconnect();
		}
	}
	
	void setTimeout() {
		
	}
	
	int Connect() {
		cout << ip <<endl;
		cout << port <<endl;
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
	
	int Disconnect() {
		connected = false;
		close(socketfd);
	}
	
	bool Connected() {
		return connected;
	}
	
};

vector<Matrix> matrixs;

// ssize_t bytes_sent;

void timeoutService() {
	
}


int connectMatrix(const char* ip, const char* port) {

}


struct per_session_data {
    int fd;
};

static void INT_HANDLER(int signo) {
    //destroy_flag = 1;
}


int main() {
	
	// int status;
    // ssize_t bytes_sent;
    // struct addrinfo host_info;
	// struct addrinfo *host_info_list;
    // //int len = strlen(buffer);
	
	// //struct sockaddr_in serv_addr;
  	// //struct hostent *server;
    // int socketfd;  
      
    // memset(&host_info, 0, sizeof host_info);
	// host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  	// host_info.ai_socktype = SOCK_STREAM;
      
	// status = getaddrinfo("192.168.180.98", "5555", &host_info, &host_info_list);
	// if (status == 0) {
	// 	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
	// 	host_info_list->ai_protocol);
	// 	if (socketfd != -1) {
	// 		status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	// 		if (status != -1) {
	// 			//connected = true;
    //             printf("Socket made succefully!! socketfd=%d\n", socketfd);
	// 		} else cout << "Failed when connecting socket" <<endl;
	// 	} else cout << "Failed when creating socket" <<endl;
	// } else {
	// 	cout << "Failed to get address" <<endl;
	// }
	
	
	// const char *interface = NULL;
    // struct lws_context_creation_info info;
    // struct lws_protocols protocol;
    // struct lws_context *context;
    // // Not using ssl
    // const char *cert_path = NULL;
    // const char *key_path = NULL;
    // // no special options
    // int opts = 0;
  	// //* register the signal SIGINT handler */
    // struct sigaction act;
    // act.sa_handler = INT_HANDLER;
    // act.sa_flags = 0;
    // sigemptyset(&act.sa_mask);
    // sigaction( SIGINT, &act, 0);
	
	Matrix matrix("192.168.180.98", "5555");
	matrix.Connect();
	
	
	
	// while(1) {
		
	// }
	
	
// clock_t start, end;
// double cpu_time_used;

// start = clock();

// end = clock();
// cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	int con, cpu;
	while(1) {
		
		  fd_set rfds;
           struct timeval tv;
           int retval;

           /* Watch stdin (fd 0) to see when it has input. */

           FD_ZERO(&rfds);
           FD_SET(0, &rfds);

           /* Wait up to five seconds. */

           tv.tv_sec = 0;
           tv.tv_usec = 900000;

           retval = select(1, &rfds, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */

           if (retval == -1)
               perror("select()");
           else if (retval) {
            	printf("retval %d", retval);
			   printf("Data is available now.\n");
			   int count;
			   char buffer[1024];
			   MattiRequest *request = new MattiRequest();
			   count = read(1, buffer, 1024);
			   printf("%s \n", buffer);
			   retval = 0;
               /* FD_ISSET(0, &rfds) will be true. */
		   }
           else
               printf("No data within five seconds.\n");

		matrix.check();
		if (!matrix.Connected()) matrix.Connect();
		//cout << "socket fd " << socketfd << endl;
		matrix.setVideo(con, cpu);
		

		//char buffer[6] = {0x2, 71, 128 + con, 128 + cpu, 0x3};
		//int len = strlen(buffer);
		//bytes_sent = send(socketfd, buffer, len, 0);
	}
		
	return 0;
}
