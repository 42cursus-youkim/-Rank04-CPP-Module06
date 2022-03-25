
#ifndef __UTIL_H__
#define __UTIL_H__

#include <locale>
#include <string>
using std::string;

enum strLiteralType { intType, charType, floatType, doubleType, noneOfAbove };

string strTrim(const string& str);
strLiteralType findType(const string& str);
// bool isChar(const string& str);
// bool isInt(const string& str);
// bool isFloat(const string& str);
// bool isDouble(const string& str);

#endif  // __UTIL_H__