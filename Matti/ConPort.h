#ifndef CONPORT_H
#define CONPORT_H

#include <memory>

#include "IMatrixConnection.h"
#include "Matrix.h"

using namespace std;

class ConPort
{
	unique_ptr<IMatrixConnection> matrixConnection;
	int value;
	int maxValue;
public:
	ConPort();
	~ConPort();
};

#endif // !CONPORT_H