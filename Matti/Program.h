#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include <vector>

#include "ConPortMode.h";
#include "CpuPortMode.h";

using namespace std;

class Program
{
	vector<unique_ptr<ConPortMode>> conPortInstructions;
	vector<unique_ptr<CpuPortMode>> cpuPortInstructions;
public:
	Program();
	~Program();
};


#endif // !PROGRAM_H
