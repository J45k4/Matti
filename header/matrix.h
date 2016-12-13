#ifndef MATRIX_H
#define MATRIX_H

#include <string>

#include <queue>
#include <functional>

#include "AllConnections.pb.h"

using namespace std;
//namespace dbo = Wt::Dbo;

// #define SET_VIDEO_SIGNAL 0x47
// #define TURN_CON_OFF 0x48
// #define SET_ALL_VIDEO_SIGNALS 0x49
// #define TURN_OFF_ALL_CON_PORTS 0x4A
// #define SET_KWM_SIGNAL 0x4B
// #define TURN_CPU_OFF 0x4C
// #define SET_ALL_KWM_SIGNALS 0x4D
// #define TURN_OFF_ALL_CPU_PORTS 0x4E
// #define ESTABLISH_BIDIRECTIONAL_CONNECTION 0x4F
// const char DISCONNECT_CON = 0x50
// #define SET_MATRIX_FULL_SETUP 0x51
// #define RESET_MATRIX 0x52
// #define REPORT_COMPLETE_SETUP 0x53

class Matrix {
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
	Matrix(const char *ip, const char* port, int numOfCons, int numOfCpus);
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
