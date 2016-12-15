#ifndef CPUPORTMODE_H
#define CPUPORTMODE_H

#include <memory>

#include "CpuPort.h"

using namespace std;

class CpuPortMode
{
	unique_ptr<CpuPort> cpuPort;
	int value;
	bool mode;

public:
	CpuPortMode();
	~CpuPortMode();
};


#endif // !CPUPORTMODE_H

