#include <cstdlib>
#include <ctime>
#include <iostream>
#include "color.hpp"
#include "type.hpp"

using std::cout;

int main() {
  {
    cout << HYEL "[[Pointers]]\n" END;
    std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++) {
      Base* p = generate();
      identify(p);
      delete p;
    }
    cout << HYEL "[[Null Pointer]]\n" END;
    identify(NULL);
  }
  {
    cout << HYEL "\n[[References]]\n" END;
    A a;
    identify(a);
    B b;
    identify(b);
    C c;
    identify(c);

    Base& aRef = a;
    identify(aRef);
    Base& bRef = b;
    identify(bRef);
    Base& cRef = c;
    identify(cRef);
  }
}
