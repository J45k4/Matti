#ifndef CPUPORT_H
#define CPUPORT_H

#include <memory>

#include "IMatrixConnection.h"
#include "Matrix.h"

using namespace std;

class CpuPort
{
	unique_ptr<IMatrixConnection> matrixConnection;
	int value;
	int maxValue;
public:
	CpuPort();
	~CpuPort();
};

#endif // !CPUPORT_H