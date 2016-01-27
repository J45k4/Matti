#include "api.h"

API::API()
  {

  }
  
API::~API() {
    beingDeleted();
}


void API::handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) {
    //response.out() << "Ei mittaa viela" << std::endl;
    response.setMimeType("text/html");
    if (!request.getParameterValues("device_id").empty() && !request.getParameterValues("cpu").empty() && !request.getParameterValues("con").empty() && !request.getParameterValues("mode").empty() && !request.getParameterValues("token").empty()) {
        
    }

}

void Send_to_matrix() {
            cout << "Setting port mode to " << request.getParameterValues("mode")[0] <<endl;
        MatrixConnection connection("192.168.180.98", "5555");
        char buffer[6] = {0x2, 71, 128 + stoi(request.getParameterValues("con")[0]), 128 + stoi(request.getParameterValues("cpu")[0]), 0x3};
        connection.Send(buffer);
}