
#include <stdlib.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>

#include "matti.h"
#include "MattiRequest.pb.h"

#include "Matrix.pb.h"
#include "Matrixs.pb.h"
#include "Timer.pb.h"
#include "Timers.pb.h"
#include "Program.pb.h"
#include "Programs.pb.h"
#include "matrix.h"

using namespace std;

int matrixid = 1;

Matti::Matti(int argc, char *argv[]) {
	parseArgs(argc, argv);
	createServer();
}

Matti::~Matti() {

}

void Matti::parseArgs(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (i < argc) {
                switch(argv[i][1]) {
                    case 'p': {
                        port = atoi(argv[++i]);
                    }
                        break;                
                }
            } else {
                cout << "Väärä määrä parametreja" << endl;
            }
        }
    }
}

void Matti::createServer() {
	if (port > -1) {
	int maxfd, newClient, nready, i;
    int server_len, client_len;
    struct sockaddr_in server , client;
    struct timeval tv;
    
    int max_fd = 0;
     
    //Create socket
    serverfd = socket(AF_INET , SOCK_STREAM , 0);
    if (serverfd == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    bind(serverfd,(struct sockaddr *)&server , sizeof(server));
    if (errno == EADDRINUSE) {
        cout << "Osoite on jo käytössä" <<endl;
    }
	listen(serverfd , 3);

    memset(poll_set, '\0', sizeof(poll_set));
    poll_set[0].fd = serverfd;
    poll_set[0].events = POLLIN;
    numfds++;

	} else {
		cout << "Port is not defined" <<endl;
	}
}

void Matti::refresh() {
    int fd_index;
    int nread;
	int server_len, client_len;
	int client_sockfd;
	char buffer[1024];

	struct sockaddr_un client_address;
    poll(poll_set, numfds, 2);
    for(fd_index = 0; fd_index < numfds; fd_index++) {
        if( poll_set[fd_index].revents & POLLIN ) {
            if(poll_set[fd_index].fd == serverfd) {
                client_len = sizeof(client_address);
                client_sockfd = accept(serverfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);   
                poll_set[numfds].fd = client_sockfd;
                poll_set[numfds].events = POLLIN;
                numfds++;
                printf("Adding client on fd %d\n", client_sockfd);
            }
            else {
                ioctl(poll_set[fd_index].fd, FIONREAD, &nread);
				if( nread == 0 )
            	{
                	close(poll_set[fd_index].fd);           
                	poll_set[fd_index].events = 0;
                	printf("Removing client on fd %d\n", poll_set[fd_index].fd);
                	int i;
                	for( i = fd_index; i<numfds; i++)
                	{
                	    poll_set[i] = poll_set[i + 1];
                	}
                	numfds--;
            	}
            	else {
                	int bytes = read(poll_set[fd_index].fd, &buffer, sizeof(buffer));
                	fflush(stdout);
                    parseRequest(buffer, poll_set[fd_index].fd);
                    //write(poll_set[fd_index].fd, responseData.c_str(), sizeof(responseData));	            
            	}
            }           
        }       
    }
}

void Matti::parseRequest(char *buffer, int socketfd) {
    MattiRequest *request = new MattiRequest();
    request->ParseFromString(buffer);
    MattiResponse *response = new MattiResponse();
    
    switch(request->requestMessage_case()) {
        case 2: {
            switch(request->requestvalues()) {
                case 1: {
                    Matrixs *matrixProtos = new Matrixs();
                    for (map<int, Matrix*>::iterator it = matrixs.begin(); it != matrixs.end(); it++) {
                        Matrix *matrix = it->second;
                        MatrixProto *matrixProto = matrixProtos->add_matrixs();
                        matrixProto->set_ip(matrix->getIp());
                        matrixProto->set_port(atoi(matrix->getPort().c_str()));
                        matrixProto->set_numconports(matrix->getNumOfCons());
                        matrixProto->set_numcpuports(matrix->getNumOfCpus());         
                    }
                    response->set_allocated_matrixs(matrixProtos);
                    sendResponse(response, socketfd);
                    break;
                }
                case 2: {
                    Timers * timerProtos = new Timers();
                    for (list<Timer>::iterator it = timers.begin(); it != timers.end(); it++) {
                        Timer* timerproto = timerProtos->add_timers();
                        timerproto->set_programid((*it).programid());
                        timerproto->set_repeattimes((*it).repeattimes());
                        timerproto->set_starttime((*it).starttime());
                    }
                    response->set_allocated_timers(timerProtos);
                    sendResponse(response, socketfd);
                    break;
                }
                case 3: {
                    Programs *programProtos = new Programs();
                    for (list<Program>::iterator it = programs.begin(); it != programs.end(); it++) {
                        Program* programproto = programProtos->add_programs();
                        programproto->CopyFrom(*it);
                    }
                    response->set_allocated_programs(programProtos);
                    sendResponse(response, socketfd);
                    break;
                }
            }
            break;
        }
        case 3: {
            int matrixId = request->requestmatrixstates();
            if (matrixs.find(matrixId) != matrixs.end()) {
                matrixs[matrixId]->requestAllStates([&] (AllConnections * allConnections) {
                    response->set_allocated_connections(allConnections);
                });
            }
            break;
        }
        case 4: {
            VideoConnection videoConnection = request->insertvideoconnection();
            int matrixId = videoConnection.matrixid();
            if (matrixs.find(matrixId) != matrixs.end()) {
                matrixs[matrixId]->setVideo(videoConnection.con(), videoConnection.cpu());
            }
            break;
        }
        case 5: {
            KwmConnection kwmConnection = request->insertkwmconnection();
            int matrixId = kwmConnection.matrixid();
            if (matrixs.find(matrixId) != matrixs.end()) {
                matrixs[matrixId]->setKwm(kwmConnection.con(), kwmConnection.cpu());
            }
            break;
        }
        case 6: {
            MatrixProto matrixProto = request->insertmatrix();
            Matrix *matrix = new Matrix(matrixProto.ip().c_str(), matrixProto.port(), (int)matrixProto.numconports(), (int)matrixProto.numcpuports());
            matrixs[matrixId++] = matrix;
            break;
        }
        case 7: {
            break;
        }
        case 8: {
            break;
        }
        case 9: {
            break;
        }
        case 10: {
            break;
        }
        case 11: {
            break;
        }
        case 12: {
            break;
        }
        case 13: {
            break;
        }
    }
}  

void Matti::sendResponse(MattiResponse *response, int fd) {
    string responseData;
    response->SerializeToString(&responseData);          
    write(fd, responseData.c_str(), responseData.length());
}