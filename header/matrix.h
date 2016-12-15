#ifndef MATRIX_H
#define MATRIX_H

#include <string>

#include <queue>
#include <functional>

#include "AllConnections.pb.h"

using namespace std;

class Matrix {
	int id;
	int socketfd;
	string ip;
	string port;
	
	bool connected;
	
	float timeout = 50.0;
	float requestAllStatesTimeout = 0.200;

	time_t lastPacket;
	time_t lastRequestAllStates;
	unsigned int *videoConnections;
	unsigned int *kwmConnections;

	int numOfCons;
	int numOfCpus;

	deque<function<void(AllConnections *allConnections)>> requestAllStatesCallbacks;

	int setNonblocking(int fd);
	void sendBuffer(unsigned char *buffer);
	void Check();
	void setNonblocking();
	
	void emptyRequestAllStatesQueue();

public:
	Matrix(const char *ip, const char* port, int numOfCons, int numOfCpus, int id);
	~Matrix();
	
	unsigned int *getVideoConnections();
	unsigned int *getKwmConnections();
	
 	void setVideo(unsigned char con, unsigned char cpu);
	void conOutputOff(unsigned char con);
	void setAllVideo(unsigned char *con, unsigned char *cpu);
	void turnOffAllConPorts();
	void setKwm(unsigned char con, unsigned char cpu);
	void kwmOutputOff(unsigned char cpu);
	void setAllKwm(unsigned char *cpu, unsigned char *con);
	void turnOffAllCpuPorts();
	void establishBidirectionalConnection(unsigned char con, unsigned char cpu);
	void disconnectCon(unsigned char con);
	void setMatrixCompleteSetup(unsigned char *values);
	void reset();
	void requestAllStates(function<void(AllConnections *allConnections)> callback);
	void setTimeout();
	void Connect();
	void Disconnect();
	bool Connected();

	void refresh();

	string getIp();
	string getPort();
	int getNumOfCons();
	int getNumOfCpus();
	
};

#endif // MATRIX_H
