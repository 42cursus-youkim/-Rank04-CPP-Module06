#include "Scalar.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "util.hpp"

using std::string;

// Constructors & Destructor
Scalar::Scalar(const Scalar& other)
    : _value(other._value),
      _type(other._type),
      _charValue(other._charValue),
      _intValue(other._intValue),
      _floatValue(other._floatValue),
      _doubleValue(other._doubleValue) {}

Scalar::Scalar(string value) : _value(strTrim(value)), _type(findType(value)) {
  // const string typeStr[] = {"int", "char", "float", "double", "error"};
  // std::cout << "type is " << typeStr[_type] << std::endl;

  assert(std::numeric_limits<float>::is_iec559);
  assert(std::numeric_limits<float>::has_quiet_NaN);
  assert(std::numeric_limits<double>::is_iec559);
  assert(std::numeric_limits<double>::has_quiet_NaN);
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
      if (_value == "-inff")
        _doubleValue = -std::numeric_limits<float>::infinity();
      else if (_value == "+inff")
        _doubleValue = std::numeric_limits<float>::infinity();
      else if (_value == "nanf")
        _doubleValue = std::numeric_limits<float>::quiet_NaN();
      else
        _floatValue =
            std::strtof(_value.substr(0, _value.length() - 1).c_str(), NULL);
      castOtherValues(_floatValue);
      break;
    case doubleType:
      if (_value == "-inf")
        _doubleValue = -std::numeric_limits<double>::infinity();
      else if (_value == "+inf")
        _doubleValue = std::numeric_limits<double>::infinity();
      else if (_value == "nan")
        _doubleValue = std::numeric_limits<double>::quiet_NaN();
      else
        _doubleValue = std::strtod(_value.c_str(), NULL);
      _doubleValue = std::strtod(_value.c_str(), NULL);
      castOtherValues(_doubleValue);
      break;
    default:
      break;
  }
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

// Getters/Setters
string Scalar::getValue() const {
  return _value;
}

// Methods
string Scalar::charRepr() const {
  if (_floatValue < 0 or _floatValue > 255)
    throw ImpossibleConversionException();
  if (not std::isprint(_charValue))
    throw NonDisplayableException();
  stringstream ss;
  ss << "'" << _charValue << "'";
  return ss.str();
}

string Scalar::intRepr() const {
  if (_floatValue < std::numeric_limits<int>::lowest() or
      _floatValue > std::numeric_limits<int>::max())
    throw ImpossibleConversionException();
  stringstream ss;
  ss << _intValue;
  return ss.str();
}

string Scalar::floatRepr() const {
  if (_doubleValue < std::numeric_limits<float>::lowest() or
      _doubleValue > std::numeric_limits<float>::max())
    throw ImpossibleConversionException();
  stringstream ss;
  ss << std::fixed << std::setprecision(15) << _floatValue << "f";
  return ss.str();
}

string Scalar::doubleRepr() const {
  stringstream ss;
  ss << std::fixed << std::setprecision(15) << _doubleValue;
  return ss.str();
}

string Scalar::pairOutput(string name, reprFunc func) const {
  const string impossible = "impossible";
  stringstream ss;

  ss << name << ": ";
  if (_type == errorType)
    ss << impossible;
  else {
    try {
      ss << (this->*func)();
    } catch (Scalar::ImpossibleConversionException& e) {
      ss << impossible;
    } catch (Scalar::NonDisplayableException& e) {
      ss << "Non displayable";
    } catch (std::exception& e) {
      ss << "Well that's unexpected:" << e.what();
    };
  }
  ss << "\n";
  return ss.str();
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Scalar& scalar) {
  const string typeStr[] = {"char", "int", "float", "double"};
  Scalar::reprFunc funcs[] = {&Scalar::charRepr, &Scalar::intRepr,
                              &Scalar::floatRepr, &Scalar::doubleRepr};
  if (scalar.getValue() == "nanf" or scalar.getValue() == "nan") {
    os << "char: impossible\n";
    os << "int: impossible\n";
    os << "float: nanf\n";
    os << "double: nan\n";
  } else if (scalar.getValue() == "+inff" or scalar.getValue() == "-inff") {
    os << "char: impossible\n";
    os << "int: impossible\n";
    os << "float: " << scalar.getValue() << "\n";
    os << "double: " << scalar.getValue() << "\n";
  } else {
    for (int i = 0; i < 4; i++)
      os << scalar.pairOutput(typeStr[i], funcs[i]);
  }
  return os;
}

// Exceptions
const char* Scalar::ImpossibleConversionException::what() const throw() {
  return "Conversion impossible";
}

const char* Scalar::NonDisplayableException::what() const throw() {
  return "Non displayable";
}
