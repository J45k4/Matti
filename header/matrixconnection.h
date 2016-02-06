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
#include <list>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


struct matrix_device_id {
    char ip[20];
    char port[7];  
};

struct matrix_device {
    matrix_device_id id;
    int exTime;
    clock_t timerTime;
    int socketfd;
    matrix_device *next;
    matrix_device *last;
};

void sendBuffer(char* buffer, const char *ip, const char *port);

void mResetTimer(matrix_device *device);
void* mTimerF(void *arg);
void mClose(matrix_device *device);
void mDelete(matrix_device *device);
void mChangeLast(matrix_device *device);
void mInsert(matrix_device_id device);
int mSendBuffer(char* buffer, matrix_device_id *device_id);
int mSendBuffer(char* buffer, const char *ip, const char *port);
int mCount();
int mCreateSocket(matrix_device_id device);
char *mRceive(matrix_device *device);
matrix_device *mFindConnection(matrix_device_id device);
matrix_device *mNext(matrix_device * device);
matrix_device *mPrev(matrix_device * device);



/*class MatrixConnection {
    static list<MatrixConnection*> *connections;
	
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
    
    
    // static functions
    void sendBuffer(char *buffer, const char* ip, const char* port);
    

};*/
            
#endif // MATRIXCONNECTION_H