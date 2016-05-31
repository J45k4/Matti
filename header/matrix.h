#ifndef MATRIX_H
#define MATRIX_H

#include <Wt/Dbo/Dbo>
#include <string>

using namespace std;
//namespace dbo = Wt::Dbo;

class Matrix {
	int socketfd;
	string ip;
	string port;
	
	bool connected;
	
	float timeout = 50.0;

	time_t lastPacket;
	
public:
	Matrix(const char *ip, const char* port);
	~Matrix();
	
 	void setVideo(int con, int cpu);
	void setKwm(int con, int cpu);
	void Check();
	void setTimeout();
	int Connect();
	void Disconnect();
	bool Connected();
	
};

#endif // MATRIX_H
