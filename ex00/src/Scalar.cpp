#include "Scalar.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

// Constructors
Scalar::Scalar() : _value("error") {}

Scalar::Scalar(const Scalar& copy) {
  _value = copy.getValue();
}

Scalar::Scalar(string value) {
  _value = value;
}

// Destructor
Scalar::~Scalar() {}

// Getters / Setters
string Scalar::getValue() const {
  return _value;
}

// Methods
char Scalar::toChar() const {
  int i = toInt();
  if (i < 0 or 255 < i)
    throw ImpossibleConversionException();
  if (not isprint(i))
    throw NonDisplayableException();
  return i;
}

int Scalar::toInt() const {
  errno = 0;
  char* end;
  const char* s = _value.c_str();
  long l = std::strtol(s, &end, 10);

  if ((errno == ERANGE && l == LONG_MAX) or l > INT_MAX or
      (errno == ERANGE && l == LONG_MIN) or l < INT_MIN or *s == '\0' or
      *end != '\0')
    throw ImpossibleConversionException();
  return l;
}

float Scalar::toFloat() const {
  return 0;
}

double Scalar::toDouble() const {
  return 0;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Scalar& scalar) {
  (void)scalar;
  return os;
}

// Exceptions
const char* Scalar::ImpossibleConversionException::what() const throw() {
  return "Conversion impossible";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
