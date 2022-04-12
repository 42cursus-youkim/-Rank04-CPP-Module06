#include "Scalar.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include "util.hpp"

// Constructors & Destructor
Scalar::Scalar(const Scalar& other)
    : _value(other._value),
      _type(other._type),
      _charValue(other._charValue),
      _intValue(other._intValue),
      _floatValue(other._floatValue),
      _doubleValue(other._doubleValue) {}

Scalar::Scalar(string value) : _value(strTrim(value)), _type(findType(value)) {
  const string typeStr[] = {"int", "char", "float", "double", "error"};
  std::cout << "type is " << typeStr[_type] << std::endl;

  switch (_type) {
    case intType:
      _intValue = std::strtol(_value.c_str(), NULL, 10);
      castOtherValues(_intValue);
      break;
    case charType:
      _charValue = _value[0];
      castOtherValues(_charValue);
      break;
    case floatType:
      _floatValue =
          std::strtof(_value.substr(0, _value.length() - 1).c_str(), NULL);
      castOtherValues(_floatValue);
      break;
    case doubleType:
      _doubleValue = std::strtod(_value.c_str(), NULL);
      castOtherValues(_doubleValue);
      break;
    default:
      break;
  }
  std::cout << *this << std::endl;
}

Scalar::~Scalar() {}

// Operators
Scalar& Scalar::operator=(const Scalar& assign) {
  _value = assign._value;
  _type = assign._type;
  _charValue = assign._charValue;
  _intValue = assign._intValue;
  _floatValue = assign._floatValue;
  _doubleValue = assign._doubleValue;
  return *this;
}

// Methods
string Scalar::charRepr() const {
  if (_value.length() != 1 || !std::isprint(_charValue))
    throw NonDisplayableException();
  stringstream ss;
  ss << "'" << _charValue << "'";
  return ss.str();
}

string Scalar::intRepr() const {
  stringstream ss;
  ss << _intValue;
  return ss.str();
}

string Scalar::floatRepr() const {
  stringstream ss;
  ss << std::fixed << std::setprecision(2) << _floatValue << "f";
  return ss.str();
}

string Scalar::doubleRepr() const {
  stringstream ss;
  ss << std::fixed << std::setprecision(2) << _doubleValue;
  return ss.str();
}

string Scalar::pairOutput(string name, reprFunc func) const {
  stringstream ss;

  ss << name << ": ";
  try {
    ss << (this->*func)() << "\n";
  } catch (Scalar::ImpossibleConversionException& e) {
    ss << "impossible\n";
  } catch (Scalar::NonDisplayableException& e) {
    ss << "Non displayable\n";
  } catch (std::exception& e) {
    ss << "Well that's unexpected:" << e.what() << "\n";
  };
  return ss.str();
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Scalar& scalar) {
  const string typeStr[] = {"char", "int", "float", "double"};
  Scalar::reprFunc funcs[] = {&Scalar::charRepr, &Scalar::intRepr,
                              &Scalar::floatRepr, &Scalar::doubleRepr};
  for (int i = 0; i < 4; i++)
    os << scalar.pairOutput(typeStr[i], funcs[i]);
  return os;
}

// Exceptions
const char* Scalar::ImpossibleConversionException::what() const throw() {
  return "Conversion impossible";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
