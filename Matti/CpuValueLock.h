#ifndef CPUVALUELOCK_H
#define CPUVALUELOCK_H

#include <memory>

#include "CpuPort.h"

class CpuValueLock
{
	unique_ptr<CpuPort> cpuPort;
	int value();

public:
	CpuValueLock();
	~CpuValueLock();
};

#endif // !CPUVALUELOCK_H