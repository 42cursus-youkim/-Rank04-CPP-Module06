#include <iostream>
#include <string>
#include "Scalar.hpp"

using std::cout;
using std::string;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: ./prog.out [scalar value]" << std::endl;
    return 1;
  }
  string value = argv[1];
  Scalar scalar(value);
  cout << scalar << "\n";
}
