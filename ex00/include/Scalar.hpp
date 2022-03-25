#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>

using std::string;

class Scalar {
 private:
  string _value;

 public:
  // Constructors & Destructor
  Scalar();
  Scalar(const Scalar& copy);
  Scalar(string value);
  ~Scalar();

  // Operators
  Scalar& operator=(const Scalar& assign);

  // Getters
  string getValue() const;

  // Methods
  char toChar() const;
  int toInt() const;
  float toFloat() const;
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


std::ostream& operator<<(std::ostream& os, const Scalar& scalar);

#endif