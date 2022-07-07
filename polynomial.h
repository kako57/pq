#include "fraction.h"

#ifndef _POLYNOMIAL_H

typedef struct {
  int *coefficients;
  int degree;
} polynomial;

fraction eval(polynomial *eq, fraction f);

#define _POLYNOMIAL_H
#endif
