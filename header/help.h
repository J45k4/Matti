#ifndef HELPAPI_H
#define HELPAPI_H

#include <Wt/WResource>
#include <Wt/Http/Response>
#include <stdlib.h>
#include <string>
#include <map>
#include "matrixconnection.h"
//#include "Matrix.h"

using namespace std;

class HelpApi : public Wt::WResource
{
    ///Json::Object response;

    
public:
    HelpApi();
    
    ~HelpApi();
    
    
    virtual void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response);


};

#endif // HELPAPI_H