#ifndef __STRUTIL_H__
#define __STRUTIL_H__

#include <string>

using std::string;

string strTrim(const string& str);
char strLast(const string& str);
bool strIsOneOf(const string& str, const string strs[], int size);
bool stringHasAlpha(const string& str);
bool stringHasNoAlphaExcept(const string& str, const string& except);

#endif  // __STRUTIL_H__