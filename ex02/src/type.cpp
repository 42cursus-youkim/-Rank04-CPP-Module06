#include "type.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include "color.hpp"

using std::cout;
using std::string;

enum classType { Atype, Btype, Ctype };
const string classTypeStr[] = {HRED "A", HYEL "B", HGRN "C"};

Base* generate(void) {
  int n = std::rand() % 3;
  cout << HCYN "generated " << classTypeStr[n] << END "\n";
  switch (n) {
    case Atype:
      return new A();
    case Btype:
      return new B();
    case Ctype:
      return new C();
    default:
      return NULL;
  }
}

void identify(Base* p) {
  cout << HMAG "identified ";
  if (dynamic_cast<A*>(p))
    cout << classTypeStr[Atype];
  else if (dynamic_cast<B*>(p))
    cout << classTypeStr[Btype];
  else if (dynamic_cast<C*>(p))
    cout << classTypeStr[Ctype];
  else
    cout << "Unknown type";
  cout << "\n" END;
}

void identify(Base& p) {
  cout << HMAG "identified ";
  try {
    dynamic_cast<A&>(p);
    cout << classTypeStr[Atype] << END "\n";
    return;
  } catch (std::exception& e) {
  }
  try {
    dynamic_cast<B&>(p);
    cout << classTypeStr[Btype] << END "\n";
    return;
  } catch (std::exception& e) {
  }
  try {
    dynamic_cast<C&>(p);
    cout << classTypeStr[Ctype] << END "\n";
    return;
  } catch (std::exception& e) {
  }
  cout << "Unknown type\n";
}