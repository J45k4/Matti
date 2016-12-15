#ifndef LOCK_H
#define LOCK_H

#include <memory>
#include <vector>

#include "ConValueLock.h"
#include "CpuValueLock.h"


using namespace std;

class Lock
{
	vector<unique_ptr<ConValueLock>> conValueLocks;
	vector<unique_ptr<CpuValueLock>> cpuValueLocks;
public:
	Lock();
	~Lock();
};

#endif // !LOCK_H