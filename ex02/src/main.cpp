#include "type.hpp"

int main() {
  for (int i = 0; i < 10; i++) {
    Base* p = generate();
    identify(p);
    delete p;
  }
}