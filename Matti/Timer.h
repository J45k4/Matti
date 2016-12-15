#ifndef TIMER_H
#define TIMER_H

#include <memory>
#include <vector>

#include "Program.h"

using namespace std;

class Timer
{
	vector<unique_ptr<Program>> programs;

public:
	Timer();
	~Timer();
};

#endif // !TIMER_H

