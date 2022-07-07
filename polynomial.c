#include "polynomial.h"

fraction eval(polynomial *eq, fraction f) {
  fraction result;
  result.numerator = eq->coefficients[eq->degree];
  result.denominator = 1;

  for (int i = eq->degree - 1; i >= 0; i--) {
    fraction addend;
    addend.numerator = eq->coefficients[i];
    addend.denominator = 1;
    result = frac_add(frac_mult(result, f), addend);
  }

  return result;
}
