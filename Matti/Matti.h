#ifndef MATTI_H
#define MATTI_H

#include <memory>
#include <vector>

#include "ISerializer.h";
#include "Timer.h"
#include "Lock.h"
#include "Matrix.h"
#include "Program.h"

using namespace std;

class Matti
{
	unique_ptr<ISerializer> serializer;
	vector<unique_ptr<Lock>> locks;
	vector<unique_ptr<Timer>> timers;
	vector<unique_ptr<Matrix>> matrixs;
	vector<unique_ptr<Program>> programs;
public:
	Matti();
	~Matti();
};


#endif // !MATTI_H