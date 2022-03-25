#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>

using std::string;

class Scalar {
 public:
  // Constructors & Destructor
  Scalar();
  Scalar(const Scalar& copy);
  Scalar(string value);
  ~Scalar();

  // Operators
  Scalar& operator=(const Scalar& assign);

  // Getters / Setters
  string getValue() const;

 private:
  string _value;
};

#endif