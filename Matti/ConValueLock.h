#ifndef CONVALUELOCK_H 
#define CONVALUELOCK_H

#include <memory>

#include "ConPort.h"

class ConValueLock
{
	unique_ptr<ConPort> conPort;
	int value;

public:
	ConValueLock();
	~ConValueLock();
};

#endif // !CONVALUELOCK_H 




