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
      throw std::runtime_error("unknown type");
  }
}

void identify(Base* p) {
  cout << HMAG "identified ";
  if (p == NULL)
    cout << RED "(NULL)";
  else if (dynamic_cast<A*>(p))
    cout << classTypeStr[Atype];
  else if (dynamic_cast<B*>(p))
    cout << classTypeStr[Btype];
  else if (dynamic_cast<C*>(p))
    cout << classTypeStr[Ctype];
  else
    cout << RED "Unknown type";
  cout << "\n" END;
}

void identify(Base& p) {
  cout << HMAG "identified ";
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    cout << classTypeStr[Atype];
    goto finish;
  } catch (std::exception& e) {
  }
  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    cout << classTypeStr[Btype];
    goto finish;
  } catch (std::exception& e) {
  }
  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    cout << classTypeStr[Ctype];
    goto finish;
  } catch (std::exception& e) {
  }
  cout << RED "Unknown type\n";
finish:
  cout << END "\n";
}
