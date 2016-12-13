#include "main.h"
using namespace std;



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <poll.h>
#include <errno.h>

#include <signal.h>
#include <iostream>

#include "MattiRequest.pb.h"
#include "MattiResponse.pb.h"
#include "VideoConnection.pb.h"
#include "VideoConnections.pb.h"
#include "KwmConnections.pb.h"
#include "KwmConnection.pb.h"

#include "client.h"
#include "matrix.h"
#include "matti.h"

using namespace std;

list<Matrix> matrixs;
list<Client> clients;

#define POLL_SIZE 32

extern int errno;

int serverfd;

MattiResponse* serveRequest(MattiRequest *request, int fd);

Matrix matrix("192.168.180.98", "5555", 16, 16);

void signal_callback_handler(int signum)
{
    printf("Caught signal %d\n",signum);
    close(serverfd);
    exit(signum);
}
int bindPort = 0;

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (i < argc) {
                switch(argv[i][1]) {
                    case 'p': {
                        bindPort = atoi(argv[++i]);
                    }
                        break;                
                }
            } else {
                //cout << "Väärä määrä parametreja" << endl;
            }
        }
    }
    
    Matti matti(argc, argv);
    while(1) {
        matti.refresh();
    }

    // cout << "portti on "  << bindPort <<endl;
    
	// // signal(SIGINT, signal_callback_handler);
	
	
	// // matrix.Connect();
    
    // // ssize_t nbytes;
    
    // int maxfd, newClient, nready, i;
    // int client_sockfd;
    // int server_len, client_len;
    // struct sockaddr_in server , client;
    // struct timeval tv;
    
    // struct sockaddr_un client_address;
    
    // struct pollfd poll_set[POLL_SIZE];
    // int numfds = 0;
    // int max_fd = 0;
    
    // char buffer[1024];
     
    // //Create socket
    // serverfd = socket(AF_INET , SOCK_STREAM , 0);
    // if (serverfd == -1)
    // {
    //     printf("Could not create socket");
    // }
    // puts("Socket created");
     
    // //Prepare the sockaddr_in structure
    // server.sin_family = AF_INET;
    // server.sin_addr.s_addr = INADDR_ANY;
    // server.sin_port = htons(4445);
     
    // //Bind
    // // if( bind(serverfd,(struct sockaddr *)&server , sizeof(server)) < 0)
    // // {
    // //     //print the error message
    // //     perror("bind failed. Error");
    // //     return 1;
    // // }
    // bind(serverfd,(struct sockaddr *)&server , sizeof(server));

    // cout << errno <<endl;
    // if (errno == EADDRINUSE) {
    //     cout << "Osoite on jo käytössä" <<endl;
    // }
    // //puts("bind done");
     
    // //Listen
    // listen(serverfd , 3);
    
    // memset(poll_set, '\0', sizeof(poll_set));
    // poll_set[0].fd = serverfd;
    // poll_set[0].events = POLLIN;
    // numfds++;
    
    // maxfd = serverfd;


	// while(1) {
	// 	char ch;
    //     int fd_index;
    //     int nread;
        
    //     poll(poll_set, numfds, -1);     
    //     for(fd_index = 0; fd_index < numfds; fd_index++) {
    //         if( poll_set[fd_index].revents & POLLIN ) {
    //             if(poll_set[fd_index].fd == serverfd) {
    //                 client_len = sizeof(client_address);
    //                 client_sockfd = accept(serverfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
                     
    //                 poll_set[numfds].fd = client_sockfd;
    //                 poll_set[numfds].events = POLLIN;
    //                 numfds++;
 
 
    //                 printf("Adding client on fd %d\n", client_sockfd);
    //             }
    //             else {
    //                 ioctl(poll_set[fd_index].fd, FIONREAD, &nread);
                     
    //                 if( nread == 0 )
    //                 {
    //                     close(poll_set[fd_index].fd);           
    //                     poll_set[fd_index].events = 0;
    //                     printf("Removing client on fd %d\n", poll_set[fd_index].fd);
    //                     int i;
    //                     for( i = fd_index; i<numfds; i++)
    //                     {
    //                         poll_set[i] = poll_set[i + 1];
    //                     }
    //                     numfds--;
    //                 }
                 
    //             else {
    //                 int bytes = read(poll_set[fd_index].fd, &buffer, sizeof(buffer));
    //                 fflush(stdout);
    //                 MattiRequest *request = new MattiRequest();
    //                 request->ParseFromString(buffer);
    //                 MattiResponse *response = serveRequest(request, poll_set[fd_index].fd);
    //                 //string responseData;
	// 		        //response->SerializeToString(&responseData);          
    //                 //write(poll_set[fd_index].fd, responseData.c_str(), sizeof(responseData));	            
    //             }
    //         }           
    //     }       
    // }

    // }
		
	return 0;
}



// MattiResponse* serveRequest(MattiRequest *request, int fd) {
//     MattiResponse *response = new MattiResponse();
//     response->set_ticket(request->ticket());
//     printf("case: %d\n", request->requestMessage_case());
//     fflush(stdout);
//     switch(request->requestMessage_case()) {
//         case 2: {
// 		     matrix.setVideo(request->videoconnection().con(), request->videoconnection().cpu());
//              VideoConnection *videoConnection = new VideoConnection();
//              videoConnection->set_con(request->videoconnection().con());
//              videoConnection->set_cpu(request->videoconnection().cpu());
//              response->set_allocated_videoconnection(videoConnection);
//             break;
//         }
//         case 3: {
            
//             break;
//         }
//         case 4: {
//             printf("requstvalue %d\n", request->requestvalue().values());
//             switch(request->requestvalue().values()) {
//                 case 1: {
//                     printf("case 1");
//                     matrix.requestAllStates();
                    
//                     unsigned int *videoConnections = matrix.getVideoConnections();
//                     unsigned int *kwmConnections = matrix.getKwmConnections();
//                     MattiResponse *response = new MattiResponse();
//                     response->set_ticket(request->ticket());
                    
//                     VideoConnections *videoConnectionsMessage = new VideoConnections();
                    
//                     response->set_allocated_videoconnections(videoConnectionsMessage);
                    
//                     VideoConnection *videoConnection = videoConnectionsMessage->add_videoconnection();
//                     videoConnection->set_con(1);
//                     videoConnection->set_cpu(videoConnections[0]);
                    
//                     // VideoConnections *videoConnectionsMessage = new VideoConnections();
//                     for (int i = 0; i < 16; i++) {
//                         printf("i %d fd %d", i, fd);
//                         fflush(stdout);
//                         VideoConnection *videoConnection = videoConnectionsMessage->add_videoconnection();
//                         videoConnection->set_con(i+1);
//                         videoConnection->set_cpu(videoConnections[i]);
//                         // response = new MattiResponse();
//                         // response->set_ticket(request->ticket());
//                         //KwmConnection *kwmConnection = new KwmConnection();
//                         // kwmConnection->set_cpu(i+1);
//                         // kwmConnection->set_con(kwmConnections[i]);
//                         // response->set_allocated_kwmconnection(kwmConnection);
//                         // response->SerializeToString(&responseData);          
//                         // write(fd, responseData.c_str(), sizeof(responseData)); 
//                         // fflush(stdout);
//                         //  usleep(30000);                     
//                     }
//                     // response->set_allocated_videoconnections(videoConnectionsMessage);
//                     string responseData;
// 			        response->SerializeToString(&responseData);          
//                     write(fd, responseData.c_str(), responseData.length());
					
// 					response = new MattiResponse();
//                     response->set_ticket(request->ticket());
					
// 					KwmConnections * kwmConnectionsMessage = new KwmConnections();
// 					response->set_allocated_kwmconnections(kwmConnectionsMessage);
					
// 					for (int i = 0; i < 16; i++) {
// 						KwmConnection * kwmConnection = kwmConnectionsMessage->add_kwmconnection();
// 						kwmConnection->set_con(kwmConnections[i]);
// 						kwmConnection->set_cpu(i+1);
// 					}
					
// 			        response->SerializeToString(&responseData);          
//                     write(fd, responseData.c_str(), responseData.length());
//                 }
//             }
//         }
//         case 0: {
        
//             break;
//         }
//         default:
        
//             break;
//     }
//     return response;
// }



















                    //printf("Serving client on fd %d\n", poll_set[fd_index].fd);
                    //ch++;
                    //write(poll_set[fd_index].fd, &ch, 1);






        //  if (-1 == (nready = select(maxfd+1, &readfds, NULL, NULL, NULL)))
        //     printf("Select virhe\n");
      
      
        // printf("nready %d serverfd %d\n", nready, serverfd);
        //           nbytes = recv(newClient, buffer, sizeof(buffer), 0);
        //          printf("received %s", buffer);       
        // if (nready) {
        //     if (-1 == (newClient = accept(serverfd, NULL, NULL))) {
        //         printf("Uusi virheellinen\n");
        //     } else {
        //         // printf("Uusi yhteys\n");
        //         // FD_SET(newClient, &readfds);
        //         // if (maxfd < newClient) {
        //         //     maxfd = newClient;
        //         // }
        //         FD_SET(newClient, &master);
        //         while(1) {
        //          nbytes = recv(newClient, buffer, sizeof(buffer), 0);
        //          printf("received %s", buffer);
        //         }
        //     }
        // }
         
        //  for (i = 0; i < maxfd && nready > 0; i++) {

        //      if (FD_ISSET(i, &readfds)) {
        //          printf("isset\n");
        //          nready--;
        //          if (i == serverfd) {
        //              printf("Uusi client");
        //              if (-1 == (newClient = accept(serverfd, NULL, NULL))) {
        //                  if (errno != EWOULDBLOCK) {
                             
        //                  }
        //                  break;
        //              }
        //              else {
        //                  if (-1 == (fcntl(newClient, F_SETFD, O_NONBLOCK))) {
                             
        //                  }
                         
        //                  FD_SET(newClient, &master);
                         
        //                  if (maxfd < newClient) {
        //                      maxfd = newClient;
        //                  }
        //              }
        //          }
        //          else {
        //              nbytes = recv(i, buffer, sizeof(buffer), 0);
        //              if (nbytes <= 0) {
        //                 if (EWOULDBLOCK != errno);
        //                 break;                        
        //              }
        //              printf("Received %zi bytes", nbytes);
                     
        //          }
        //      }
        //  }









           
    //        if (-1 == (retval = select(serverfd, &rfds, NULL, NULL, &tv)) {
               
    //        }
           
    //        if (retval) {
    //            int fd = accept(serverfd, (struct sockaddr *)&client, (socklen_t*)&c);
    //            if (fd < 0) {
                   
    //            } else {
    //                Client client(fd);
    //                clients.push_back(fd);
    //            }
               
    //            if (client_sock < 0)
    //        }

    //        retval = select(1, &rfds, NULL, NULL, &tv);
    //        /* Don't rely on the value of tv now! */

    //        if (retval == -1);
    //            //perror("select()");
    //        else if (retval) {
    //         	printf("retval %d", retval);
	// 		   printf("Data is available now.\n");
	// 		   int count;
	// 		   char buffer[1024];
    //            count = read(1, buffer, 1024);
	// 		   MattiRequest *request = new MattiRequest();
    //            request->ParseFromString(buffer);
			   
	// 		   printf("%s \n", buffer);
	// 		   retval = 0;
    //            /* FD_ISSET(0, &rfds) will be true. */
	// 	   }
    //        else
    //            printf("No data within five seconds.\n");

	// 	matrix.Check();
	// 	if (!matrix.Connected()) matrix.Connect();
	// 	//cout << "socket fd " << socketfd << endl;
	// 	matrix.setVideo(con, cpu);
		

	// 	//char buffer[6] = {0x2, 71, 128 + con, 128 + cpu, 0x3};
	// 	//int len = strlen(buffer);
	// 	//bytes_sent = send(socketfd, buffer, len, 0);
	// }








     
    // //Accept and incoming connection
    // //puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);
     
    // //accept connection from an incoming client
    // client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    // if (client_sock < 0)
    // {
    //    // perror("accept failed");
    //     return 1;
    // }
    // //puts("Connection accepted");
     
    // //Receive a message from client
    // while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    // {
    //     //Send the message back to client
    //     write(client_sock , client_message , strlen(client_message));
    // }
     
    // if(read_size == 0)
    // {
    //     puts("Client disconnected");
    //     fflush(stdout);
    // }
    // else if(read_size == -1)
    // {
    //     perror("recv failed");
    // }

	// int con, cpu;















// int main(int argc, char **argv)
// {
//     // MattiApi matti;
//     // matti.Listen(5558);
//     return 0;  
// }
