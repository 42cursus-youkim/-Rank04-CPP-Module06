#include "Data.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Data& data) {
  os << "{" << data.country << ", " << data.capital << "}";
  return os;
}