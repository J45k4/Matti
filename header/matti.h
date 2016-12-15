#ifndef MATTI_H
#define MATTI_H

#define POLL_SIZE 32

#include <poll.h>
#include <list>
#include <vector>
#include <map>

#include "MatrixProto.pb.h"
#include "MatrixProtos.pb.h"
#include "TimerProto.pb.h"
#include "TimerProtos.pb.h"
#include "ProgramProto.pb.h"
#include "ProgramProtos.pb.h"
#include "LockProto.pb.h";
#include "LockProtos.pb.h";

#include "matrix.h"

#include "MattiResponse.pb.h"

using namespace std;

class Matti {
private:
	int port = 4444;

	int serverfd;

	int numfds = 0;

	int uid = 1;

	struct pollfd poll_set[POLL_SIZE];

	list<int> clientsRequestedAllStates;
	list<int> cliestsRequestedMatrixis;
	list<int> clientsRequestedPrograms;
	list<int> clientsRequestedTimers;


	map<int, Matrix*> matrixs;
	list<TimerProto> timers;
	list<ProgramProto> programs;
	vector<LockProto> locks;

	void parseArgs(int argc, char *argv[]);
	void createServer();
	void parseRequest(char *buffer, int socketfd);
	void sendResponse(MattiResponse *response, int fd);
public:
	Matti(int argc, char *argv[]);
	~Matti();

	void refresh();

};

#endif // MATTI_H