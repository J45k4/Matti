#ifndef PROGRAM_H
#define PROGRAM_H

#include <Wt/Dbo/Dbo>
#include <string>

#include "matrix_connection.h"
#include "name.h"

using namespace std;
namespace dbo = Wt::Dbo;

class Program {
  Connection connection;
  Name name;
  template<class Action>
  void persist(Action& a);  
};

#endif // PROGRAM_H
