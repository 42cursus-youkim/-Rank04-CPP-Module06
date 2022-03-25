#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include "util.hpp"

using std::string;

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

 public:
  // Constructors & Destructor
  Scalar();
  Scalar(const Scalar& other);
  Scalar(string value);
  ~Scalar();

  // Operators
  Scalar& operator=(const Scalar& assign);

  // Getters
  string getValue() const;

  // Methods
  // char toChar() const;
  int toInt() const;
  // float toFloat() const;
  double toDouble() const;

  // Exceptions
  class ImpossibleConversionException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class NonDisplayableException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

// std::ostream& operator<<(std::ostream& os, const Scalar& scalar);

#endif