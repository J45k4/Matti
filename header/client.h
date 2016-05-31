#ifndef CLIENT_H
#define CLIENT_H

class Client {
	int socketfd;
public:
	Client(int socketfd);
	~Client();
	
	int getSocketFd();
	
};

#endif // CLIENT_H