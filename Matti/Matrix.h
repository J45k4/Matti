#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <vector>

#include "IMatrixConnection.h"
#include "CpuPort.h"
#include "ConPort.h"


using namespace std;

class Matrix
{
	unique_ptr<IMatrixConnection> connection;
	vector<unique_ptr<CpuPort>> cpuPorts;
	vector<unique_ptr<ConPort>> conPorts;

public:
	Matrix();
	~Matrix();
};


#endif // !MATRIX_H
