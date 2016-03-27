#ifndef PROFILE_H
#define PROFILE_H


#include <Wt/Dbo/Dbo>
#include <string>

#include "name.h"
#include "token.h"

using namespace std;
namespace dbo = Wt::Dbo;

class Profile {
  Name name;
  Token token;
  template<class Action>
  void persist(Action& a);
};


#endif // PROFILE_H
