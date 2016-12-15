#include "IMatrixConnection.h"



IMatrixConnection::IMatrixConnection()
{
}


IMatrixConnection::IMatrixConnection(string ip, int port, int numOfCons, int numOfCpu)
{
}

IMatrixConnection::~IMatrixConnection()
{
}

void IMatrixConnection::destroy()
{
}

void IMatrixConnection::setVideo(int con, int cpu)
{
}

void IMatrixConnection::setKwm(int con, int cpu)
{
}

void IMatrixConnection::turnConPortOff(int con)
{
}

void IMatrixConnection::turnCpuPortOff(int cpu)
{
}

void IMatrixConnection::turnOffAllConPorts()
{
}

void IMatrixConnection::turnOffAllCpuPorts()
{
}

void IMatrixConnection::setAllVideo(int cons[], int cpus[])
{
}

void IMatrixConnection::disconnectCon(int con)
{
}

void IMatrixConnection::setMatrixCompleteSetup(int values)
{
}

void IMatrixConnection::reset()
{
}

void IMatrixConnection::requestAllStates(function<void()> callback)
{
}
