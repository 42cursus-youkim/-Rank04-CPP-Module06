#include "type.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;

enum classType { Atype, Btype, Ctype };

Base* generate(void) {
  int n = std::rand() % 3;
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
  if (static_cast<A*>(p))
    cout << "A\n";
  else if (static_cast<B*>(p))
    cout << "B\n";
  else if (static_cast<C*>(p))
    cout << "C\n";
  else
    cout << "Unknown type\n";
}

// void identify(Base& p) {}