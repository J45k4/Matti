#ifndef SETAPI_H
#define SETAPI_H

#include <Wt/WResource>
#include <Wt/Http/Response>
#include <stdlib.h>
#include <string>
#include <map>
#include "Matrix.h"

using namespace std;

class SetApi : public Wt::WResource
{
    Json::Object response;

    
public:
    SetApi();
    
    ~SetApi();
    
    
    virtual void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response);


};

#endif // SETAPI_H