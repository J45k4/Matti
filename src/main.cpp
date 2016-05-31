#include "main.h"
#include "mattiapi.h"

using namespace std;



#include <stdio.h>

#include <netinet/tcp.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <string>
#include <thread>
#include <list>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fcntl.h>

#include "MattiRequest.pb.h"

#include "client.h"
#include "matrix.h"

using namespace std;

list<Matrix> matrixs;
list<Client> clients;


int main() {
	
	
	// Matrix matrix("192.168.180.98", "5555");
	// matrix.Connect();
    
    ssize_t nbytes;
    
    int serverfd, maxfd, newClient, nready, i;
    struct sockaddr_in server , client;
    struct timeval tv;
    
    fd_set master, readfds;

    char buffer[1024];
     
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
    server.sin_port = htons(4446);
     
    //Bind
    if( bind(serverfd,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    //puts("bind done");
     
    //Listen
    listen(serverfd , 3);

    fd_set rfds;
    
    FD_ZERO(&readfds);
    FD_ZERO(&master);
    
    FD_SET(serverfd, &master);
    
    maxfd = serverfd;
    tv.tv_sec = 0;
    tv.tv_usec = 900000;
	while(1) {
		memcpy(&readfds, &master, sizeof(master));          
           


         if (-1 == (nready = select(maxfd+1, &readfds, NULL, NULL, NULL)))
            printf("Select virhe\n");
      
      
        printf("nready %d serverfd %d\n", nready, serverfd);

        if (nready) {
            if (-1 == (newClient = accept(serverfd, NULL, NULL))) {
                printf("Uusi virheellinen\n");
            } else {
                printf("Uusi yhteys\n");
                FD_SET(newClient, &master);
                 nbytes = recv(newClient, buffer, sizeof(buffer), 0);
                 printf("received %s", buffer);
            }
        }
         
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
         
    }

           
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
		
	return 0;
}

















     
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
