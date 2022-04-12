#include "strutil.hpp"

char strLast(const string& str) {
  return str[str.length() - 1];
}

string strTrim(const string& str) {
  size_t first = str.find_first_not_of(" \n\r\t");
  size_t last = str.find_last_not_of(" \n\r\t");
  return str.substr(first, (last - first + 1));
}

bool strIsOneOf(const string& str, const string strs[], int size) {
  for (int i = 0; i < size; i++)
    if (str == strs[i])
      return true;
  return false;
}

bool stringHasAlpha(const string& str) {
  for (unsigned int i = 0; i < str.length(); i++)
    if (isalpha(str[i]))
      return true;

  return false;
}

bool stringHasNoAlphaExcept(const string& str, const string& except) {
  for (unsigned int i = 0; i < str.length(); i++)
    if (isalpha(str[i]) and except.find(str[i]) == string::npos)
      return false;

  return true;
}
