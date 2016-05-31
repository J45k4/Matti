#ifndef MATTIAPI_H
#define MATTIAPI_H

#include  <sys/types.h>

class MattiApi {
	pid_t processPid;
	int destroy_flag = 0;
	
	
public:
	MattiApi();
	~MattiApi();
	
	void Listen(int port);
};

int websocket_write_back(struct lws *wsi_in, char *str, int str_size_in);

static void INT_HANDLER(int signo);

#endif // MATTIAPI_H