#ifndef MATRIX_H
#define MATRIX_H

#include <Wt/Dbo/Dbo>
#include <string>

using namespace std;
namespace dbo = Wt::Dbo;

class Matrix {
  string ip;
  int port;
  template<class Action>
  void persist(Action& a);
};

#endif // MATRIX_H
