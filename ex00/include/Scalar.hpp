#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "util.hpp"

using std::string;
using std::stringstream;

class Scalar {
 private:
  string _value;
  strLiteralType _type;
  char _charValue;
  int _intValue;
  float _floatValue;
  double _doubleValue;

  template <typename T>
  void castOtherValues(T value) {
    if (_type != intType)
      _intValue = static_cast<int>(value);
    if (_type != charType)
      _charValue = static_cast<char>(value);
    if (_type != floatType)
      _floatValue = static_cast<float>(value);
    if (_type != doubleType)
      _doubleValue = static_cast<double>(value);
  }

  // Disabled Members
  Scalar();

 public:
  // Constructors & Destructor
  Scalar(string value);
  Scalar(const Scalar& other);
  Scalar& operator=(const Scalar& assign);
  ~Scalar();

  // Methods
  string charRepr() const;
  string intRepr() const;
  string floatRepr() const;
  string doubleRepr() const;

  typedef string (Scalar::*reprFunc)() const;
  string pairOutput(string name, reprFunc func) const;

  // Exceptions
  class ImpossibleConversionException;
  class NonDisplayableException;
};

class Scalar::ImpossibleConversionException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Scalar::NonDisplayableException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Scalar& scalar);

#endif
