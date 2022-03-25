#include "util.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include "strutil.hpp"

// error handling
static bool isResultValid(const string& str, char* end_str) {
  return not(errno == ERANGE or *end_str != '\0' or end_str == str.c_str());
}

// Type identification
static bool isInt(const string& str) {
  if (str.find('.') != string::npos or stringHasAlpha(str))
    return false;

  errno = 0;
  const char* s = str.c_str();
  char* end_str;
  std::strtol(s, &end_str, 10);
  return isResultValid(str, end_str);
}

static bool isChar(const string& str) {
  return str.length() == 1;
}

static bool isFloat(const string& str) {
  const string pseudo[] = {"-inff", "+inff"};
  if (strIsOneOf(str, pseudo, 2))
    return true;
  if (strLast(str) != 'f' or not stringHasNoAlphaExcept(str, "f"))
    return false;

  errno = 0;
  char* end_str;
  string strWithoutF = str.substr(0, str.length() - 1);
  strtof(strWithoutF.c_str(), &end_str);
  return isResultValid(strWithoutF, end_str);
}

static bool isDouble(const string& str) {
  const string pseudo[] = {"-inf", "+inf", "nan"};
  if (strIsOneOf(str, pseudo, 3))
    return true;
  if (strLast(str) == '.' or stringHasAlpha(str))
    return false;

  errno = 0;
  char* end_str;
  strtod(str.c_str(), &end_str);
  return isResultValid(str, end_str);
}

typedef bool (*checkFunc)(const string&);

strLiteralType findType(const string& str) {
  checkFunc checkFuncs[] = {isInt, isChar, isFloat, isDouble};
  for (int i = 0; i < 4; i++) {
    if (checkFuncs[i](str))
      return (strLiteralType)i;
  }
  return noneOfAbove;
}