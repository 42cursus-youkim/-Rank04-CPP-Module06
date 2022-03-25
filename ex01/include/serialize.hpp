#ifndef __SERIALIZE_H__
#define __SERIALIZE_H__

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif  // __SERIALIZE_H__