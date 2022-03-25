#include "Scalar.hpp"

// Constructors
Scalar::Scalar() {
  _value = "";
}

Scalar::Scalar(const Scalar& copy) {
  _value = copy.getValue();
}

Scalar::Scalar(string value) {
  _value = value;
}

// Destructor
Scalar::~Scalar() {}

// Operators
Scalar& Scalar::operator=(const Scalar& assign) {
  _value = assign.getValue();
  return *this;
}

// Getters / Setters
string Scalar::getValue() const {
  return _value;
}
