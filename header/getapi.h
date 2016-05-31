#ifndef GETAPI_H
#define GETAPI_H

#include <Wt/WResource>
#include <Wt/Http/Response>
#include <stdlib.h>
#include <string>
#include <map>
#include "matrixconnection.h"
//#include "Matrix.h"

using namespace std;

class GetApi : public Wt::WResource
{
    ///Json::Object response;

    
public:
    GetApi();
    
    ~GetApi();
    
    
    virtual void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response);


};

#endif // GETAPI_H