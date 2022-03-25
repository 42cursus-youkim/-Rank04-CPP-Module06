#include "Scalar.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "util.hpp"

// Constructors
Scalar::Scalar() : _value("error") {}

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
    // TODO: convert isTYPE funcs to toTYPE that throws exception
    // they will be used on below switch cases
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
  std::cout << "int :" << _intValue << "\nchar :" << _charValue
            << "\nfloat :" << _floatValue << "\ndouble :" << _doubleValue
            << std::endl;
}

// Destructor
Scalar::~Scalar() {}

// Getters / Setters
string Scalar::getValue() const {
  return _value;
}
// // Overloaded << operator

// template <typename T>
// std::ostream& pairOutput(std::ostream& os,
//                          string name,
//                          const Scalar& scalar,
//                          T (Scalar::*func)(void) const) {
//   os << name << ": ";
//   try {
//     os << (scalar.*func)() << "\n";
//   } catch (Scalar::ImpossibleConversionException& e) {
//     os << "impossible\n";
//   } catch (Scalar::NonDisplayableException& e) {
//     os << "Non displayable\n";
//   } catch (std::exception& e) {
//     os << "Well that's unexpected:" << e.what() << "\n";
//   };
//   return os;
// }

// std::ostream& operator<<(std::ostream& os, const Scalar& scalar) {
//   pairOutput(os, "char", scalar, &Scalar::toChar);
//   pairOutput(os, "int", scalar, &Scalar::toInt);
//   pairOutput(os, "float", scalar, &Scalar::toFloat);
//   pairOutput(os, "double", scalar, &Scalar::toDouble);
//   return os;
// }

// Exceptions
const char* Scalar::ImpossibleConversionException::what() const throw() {
  return "Conversion impossible";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
