
#ifndef IMATRIXCONNECTION_H
#define IMATRIXCONNECTION_H

#include <vector>
#include <cstdint>
#include <functional>
#include <string>

using namespace std;

class IMatrixConnection
{
	virtual int readNonBlock() = 0;
	virtual void disconnect() = 0;
	virtual void sendBuffer(unsigned char *buffer) = 0;
public:
	IMatrixConnection(string ip, int port, int numOfCons, int numOfCpu);
	~IMatrixConnection();

	void destroy();
	void setVideo(int con, int cpu);
	void setKwm(int con, int cpu);
	void turnConPortOff(int con);
	void turnCpuPortOff(int cpu);
	void turnOffAllConPorts();
	void turnOffAllCpuPorts();
	void setAllVideo(int cons[], int cpus[]);
	void disconnectCon(int con);
	void setMatrixCompleteSetup(int values);
	void reset();
	void requestAllStates(function<void()> callback);



};


#endif //IMATRIXCONNECTION_H