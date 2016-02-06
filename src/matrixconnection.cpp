#include "matrixconnection.h"


pthread_t timerThread;

matrix_device *firstDevice = NULL;



void sendBuffer(char* buffer, const char *ip, const char *port) {
    int status;
    ssize_t bytes_sent;
    struct addrinfo host_info;
	struct addrinfo *host_info_list;
    int len = strlen(buffer);
	
	//struct sockaddr_in serv_addr;
  	//struct hostent *server;
    int socketfd;  
      
    memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  	host_info.ai_socktype = SOCK_STREAM;
      
	status = getaddrinfo(ip, port, &host_info, &host_info_list);
	if (status == 0) {
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
		host_info_list->ai_protocol);
		if (socketfd != -1) {
			status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
			if (status != -1) {
				//connected = true;
                printf("Socket made succefully!! socketfd=%d\n", socketfd);
			} else cout << "Failed when connecting socket" <<endl;
		} else cout << "Failed when creating socket" <<endl;
	} else {
		cout << "Failed to get address" <<endl;
	}
    
    bytes_sent = send(socketfd, buffer, len, 0);
    if (bytes_sent < 1) {
        printf("Error while sending...");
    }
    
}

void mResetTimer(matrix_device *device) {
    device->timerTime = clock();
}

void* mTimerF(void *arg) {
    for (matrix_device *it = firstDevice; it != it->last; it = it->next) {
        if ((double)(clock() - it->timerTime) / CLOCKS_PER_SEC > it->exTime) {
            mClose(it);
        }
    }
}

void mClose(matrix_device *device) {
    close(device->socketfd);
    mDelete(device);
    
}

void mDelete(matrix_device *device) {
    if (mCount() > 1) {
        if (device == device->last) {
            mChangeLast(mPrev(device));
        } else {
            mPrev(device)->last = device->next; 
        }
    } else {
        firstDevice = NULL;
    }
    free(device);
    device = NULL;
}

void mChangeLast(matrix_device *device) {
    matrix_device *it = firstDevice;
    for (matrix_device *it = firstDevice; it != it->last; it = it->next) {
        it->last = device;
    }
}

void mInsert(matrix_device device) {
    if (firstDevice != NULL) {
        firstDevice->last->next = &device;
        firstDevice->last = &device;
        device.last = &device;
        device.next = firstDevice;
    } else {
        firstDevice = &device;
        firstDevice->next = NULL;
        firstDevice->last = firstDevice;
    }
}

int mSendBuffer(char* buffer, matrix_device_id device_id) {
    printf("mSendBuffer arvoilla: ip=%s port%s\n", device_id.ip, device_id.port);
    matrix_device *device = mFindConnection(device_id);
    if (device != NULL) {
        int socketfd = device->socketfd;
        printf("socketfd=%d", device->socketfd);
       device->timerTime = clock();
       ssize_t bytes_sent;
	   int len = strlen(buffer);
       printf("Sending buffer now to socket %d ...\n", socketfd);
       bytes_sent = send(socketfd, buffer, len, 0);
       printf("Sended %d bytes\n", bytes_sent);
       
       return bytes_sent;
    } else {
        printf("Connection failed");
    }
}

int mSendBuffer(char* buffer, const char *ip, const char *port) {
    matrix_device_id id;
    sprintf(id.ip, ip);
    sprintf(id.port, port);
    return mSendBuffer(buffer, id);
}

int mCount() {
    int i = 0;
    for (matrix_device *it = firstDevice; it != it->last; it = it->next, i++);
    return i;
}

int mCreateSocket(matrix_device_id device) {
    int status;
    struct addrinfo host_info;
	struct addrinfo *host_info_list;
	
	//struct sockaddr_in serv_addr;
  	//struct hostent *server;
    int socketfd;  
      
    memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  	host_info.ai_socktype = SOCK_STREAM;
      
	status = getaddrinfo(device.ip, device.port, &host_info, &host_info_list);
	if (status == 0) {
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
		host_info_list->ai_protocol);
		if (socketfd != -1) {
			status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
			if (status != -1) {
				//connected = true;
                printf("Socket made succefully!! socketfd=%d\n", socketfd);
                return socketfd;
			} else cout << "Failed when connecting socket" <<endl;
		} else cout << "Failed when creating socket" <<endl;
	} else {
		cout << "Failed to get address" <<endl;
	}
    return -1;    
}

char *mRceive(matrix_device *device) {
    char *buffer = new char[128];
    int n;
    bzero(buffer,128);
    n = read(device->socketfd,buffer,128);
    if (n < 0) {
        cout << "Error when reading from socket" <<endl;
    } 
    return buffer;    
}

matrix_device *mFindConnection(matrix_device_id device_id) {
    printf("In mFindConnection arvoilla: ip=%s port%s\n", device_id.ip, device_id.port);
    printf("%d\n", firstDevice != NULL);
    if (firstDevice != NULL) {
        printf("In mFindConnection arvoilla: ip=%s port%s\n", device_id.ip, device_id.port);
        for (matrix_device *it = firstDevice; it != it->last; it = it->next) {
            printf("In mFindConnection arvoilla: ip=%s port%s\n", device_id.ip, device_id.port);
            if (strcmp(it->id.ip, device_id.ip)==0 && strcmp(it->id.port, device_id.port)==0) {
                return it;
            }   
        }
    }
    printf("No existing connection found ...\ncreating new\n");
    matrix_device device;
    device.id = device_id;
    device.exTime = 5;
    device.timerTime = clock();
    printf("Now creating socket..\n");
    device.socketfd = mCreateSocket(device_id);
    printf("Now trying to insert new device...\n");
    mInsert(device);
    printf("New device inserted!");
    return &device;  
}

matrix_device *mNext(matrix_device * device) {
    return device->next;
}

matrix_device *mPrev(matrix_device * device) {
    matrix_device *it;
    for (it = firstDevice; it->next != device; it = it->next);
    return it;
}




























/*
MatrixConnection::MatrixConnection() {
	Init();
}

MatrixConnection::MatrixConnection(string ip, string port) {
	Init();
	Connect(ip, port);
}

//

int MatrixConnection::Init() {

	 return 0;	  
}
	
void MatrixConnection::Connect() {
	int status;
    struct addrinfo host_info;
	struct addrinfo *host_info_list;
	
	//struct sockaddr_in serv_addr;
  	//struct hostent *server;
      
    memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  	host_info.ai_socktype = SOCK_STREAM;
      
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



// static functions

void MatrixConnection::sendBuffer(char *buffer, const char* ip, const char* port) {
    
}
*/