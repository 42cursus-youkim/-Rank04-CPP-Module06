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
#define WhyCantIHaveATemplateInMyLife(name, value)         \
  do {                                                     \
    os << name << ": ";                                    \
    try {                                                  \
      os << value << "\n";                                 \
    } catch (Scalar::ImpossibleConversionException & e) {  \
      os << "impossible\n";                                \
    } catch (Scalar::NonDisplayableException & e) {        \
      os << "Non displayable\n";                           \
    } catch (std::exception & e) {                         \
      os << "Well that's unexpected:" << e.what() << "\n"; \
    }                                                      \
  } while (0)
;

std::ostream& operator<<(std::ostream& os, const Scalar& scalar) {
  WhyCantIHaveATemplateInMyLife("char", scalar.toChar());
  WhyCantIHaveATemplateInMyLife("int", scalar.toInt());
  WhyCantIHaveATemplateInMyLife("float", scalar.toFloat());
  WhyCantIHaveATemplateInMyLife("double", scalar.toDouble());
  return os;
}

// Exceptions
const char* Scalar::ImpossibleConversionException::what() const throw() {
  return "Conversion impossible";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
