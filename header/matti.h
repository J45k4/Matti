#ifndef MATTI_H
#define MATTI_H

#define POLL_SIZE 32

#include <poll.h>
#include <list>
#include <map>
#include "Timer.pb.h"
#include "Program.pb.h"
#include "matrix.h"

#include "MattiResponse.pb.h"

using namespace std;

class Matti {
private:
	int port = 4444;

	int serverfd;

	int numfds = 0;

	struct pollfd poll_set[POLL_SIZE];

	list<int> clientsRequestedAllStates;
	list<int> cliestsRequestedMatrixis;
	list<int> clientsRequestedPrograms;
	list<int> clientsRequestedTimers;

	list<Timer> timers;
	map<int,Matrix*> matrixs;
	list<Program> programs;

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