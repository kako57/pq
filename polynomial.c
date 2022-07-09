#include "polynomial.h"

fraction eval(polynomial *eq, fraction f) {
  fraction result;

  result = eq->coefficients[eq->degree];

  for (int i = eq->degree - 1; i >= 0; i--) {
    fraction addend;
    addend = eq->coefficients[i];
    result = frac_add(frac_mult(result, f), addend);
  }

  return result;
}
