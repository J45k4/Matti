#include "main.h"

using namespace std;
using namespace Wt;


int main(int argc, char **argv)
{
    Wt::WServer server(argv[0]);
    server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
    //server.addEntryPoint(Wt::Application, createRootApplication, "/");
    server.addResource(new SetApi(), "/set");
    server.addResource(new HelpApi(), "/");
    if (server.start()) {
      int sig = Wt::WServer::waitForShutdown(argv[0]);
      std::cerr << "Shutdown (signal = " << sig << ")" << std::endl;
      server.stop();
    }
    return 0;  
}