#ifndef __TYPE_H__
#define __TYPE_H__

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif  // __TYPE_H__