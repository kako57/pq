#include <stdio.h>
#include <stdbool.h>

#ifndef _FRACTION_H
typedef struct {
  int numerator;
  int denominator;
} fraction;

void print_fraction(fraction f);
fraction frac_scalar_mult(fraction f, int k);
fraction frac_reduce(fraction f);
bool frac_less(fraction f, fraction d);
bool frac_greater(fraction f, fraction d);
fraction frac_add(fraction f, fraction d);
fraction frac_mult(fraction f, fraction d);
fraction frac_div(fraction f, fraction d);

#define _FRACTION_H
#endif
