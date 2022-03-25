#ifndef __UTIL_H__
#define __UTIL_H__

enum STR2INT_ERROR { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };

STR2INT_ERROR str2int(int& i, char const* s, int base = 0);

#endif  // __UTIL_H__