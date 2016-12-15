#ifndef CONPORTMODE_H
#define CONPORTMODE_H

#include <memory>

#include "ConPort.h";

using namespace std;

class ConPortMode
{
	unique_ptr<ConPort> conPort;
	int value;
	bool mode;

public:
	ConPortMode();
	~ConPortMode();
};

#endif // !CONPORTMODE_H

