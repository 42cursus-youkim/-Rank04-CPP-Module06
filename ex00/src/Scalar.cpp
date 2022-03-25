#include "Scalar.hpp"

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
  return 0;
}

int Scalar::toInt() const {
  return 0;
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
  return "Impossible conversion";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
