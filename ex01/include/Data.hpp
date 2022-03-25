#ifndef __DATA_H__
#define __DATA_H__

#include <string>

struct Data {
  std::string country;
  std::string capital;
};

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif  // __DATA_H__