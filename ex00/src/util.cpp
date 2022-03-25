#include "util.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <string>

STR2INT_ERROR str2int(int& i, std::string& str, int base = 10) {
  errno = 0;
  char* end;
  const char* s = str.c_str();
  long l = std::strtol(s, &end, base);

  if ((errno == ERANGE && l == LONG_MAX) or l > INT_MAX)
    return OVERFLOW;
  if ((errno == ERANGE && l == LONG_MIN) or l < INT_MIN)
    return UNDERFLOW;
  if (*s == '\0' || *end != '\0')
    return INCONVERTIBLE;
  i = l;
  return SUCCESS;
}