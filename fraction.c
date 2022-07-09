#include "fraction.h"
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else if (a == 0)
    return b;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void print_fraction(fraction f) {
  if (f.denominator == 1)
    printf("%d\n", f.numerator);
  else
    printf("%d/%d\n", f.numerator, f.denominator);
}

fraction frac_scalar_mult(fraction f, int k) {
  f.numerator *= k;
  f.denominator *= k;
  return f;
}

fraction frac_reduce(fraction f) {
  int g = gcd(f.numerator, f.denominator);
  f.numerator /= g;
  f.denominator /= g;
  if (f.denominator < 0) {
    f.numerator *= -1;
    f.denominator *= -1;
  }
  return f;
}

bool frac_less(fraction f, fraction d) {
  int l = lcm(f.denominator, d.denominator);
  return f.numerator * l / f.denominator < d.numerator * l / d.denominator;
}

bool frac_greater(fraction f, fraction d) {
  return frac_less(d, f);
}

fraction frac_add(fraction f, fraction d) {
  fraction result;
  result.denominator = lcm(f.denominator, d.denominator);
  f = frac_scalar_mult(f, result.denominator / f.denominator);
  d = frac_scalar_mult(d, result.denominator / d.denominator);
  result.numerator = f.numerator + d.numerator;
  return frac_reduce(result);
}

fraction frac_mult(fraction f, fraction d) {
  f.numerator *= d.numerator;
  f.denominator *= d.denominator;
  return frac_reduce(f);
}

fraction frac_div(fraction f, fraction d) {
  f.numerator *= d.denominator;
  f.denominator *= d.numerator;
  return frac_reduce(f);
}
