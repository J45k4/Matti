#include "help.h"
//
HelpApi::HelpApi()
  {

  }
  
HelpApi::~HelpApi() {
    beingDeleted();
}


void HelpApi::handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) {
    //response.out() << "Ei mittaa viela" << std::endl;
    response.setMimeType("text/html");
    response.out() << "<h4> (url)/set?con=(con)&cpu=(cpu)&ip=(ip)&port=(port) </h4>" << std::endl;
    response.out() << "<h4> default ip:192.168.180.98 port:5555 </h4>" << std::endl;

}

/*void Send_to_matrix() {
            cout << "Setting port mode to " << request.getParameterValues("mode")[0] <<endl;
        MatrixConnection connection("192.168.180.98", "5555");
        char buffer[6] = {0x2, 71, 128 + stoi(request.getParameterValues("con")[0]), 128 + stoi(request.getParameterValues("cpu")[0]), 0x3};
        connection.Send(buffer);
}*/