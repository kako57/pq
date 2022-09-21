#include "fraction.h"

// computes the greatest common denominator/factor of two integers
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else if (a == 0)
    return b;
  return gcd(b, a % b);
}

// computes the least common multiple of two integers
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

/*
 * prints fraction in a nice format
 * if the denominator is 1, then just print it like an integer
 */
void print_fraction(fraction f) {
  if (f.denominator == 1)
    printf("%d\n", f.numerator);
  else
    printf("%d/%d\n", f.numerator, f.denominator);
}

/*
 * multiplies both numerator and denominator by a constant
 * resulting in a multiplication by k/k, which is equal to 1
 */
fraction frac_scalar_mult(fraction f, int k) {
  assert(k != 0);
  f.numerator *= k;
  f.denominator *= k;
  return f;
}

/*
 * simplifies the fraction to lowest terms
 */
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

/* compares two fractions f and d, and returns true if f < d
 * otherwise, it returns false
 */
bool frac_less(fraction f, fraction d) {
  int l = lcm(f.denominator, d.denominator);
  return f.numerator * l / f.denominator < d.numerator * l / d.denominator;
}

/*
 * compares two fractions f and d, returns true if f > d
 * otherwise, it returns false
 */
bool frac_greater(fraction f, fraction d) {
  return frac_less(d, f);
}

// adds two fractions and returns the result in lowest terms
fraction frac_add(fraction f, fraction d) {
  fraction result;
  result.denominator = lcm(f.denominator, d.denominator);
  f = frac_scalar_mult(f, result.denominator / f.denominator);
  d = frac_scalar_mult(d, result.denominator / d.denominator);
  result.numerator = f.numerator + d.numerator;
  return frac_reduce(result);
}

// multiplies two fractions and returns the result in lowest terms
fraction frac_mult(fraction f, fraction d) {
  f.numerator *= d.numerator;
  f.denominator *= d.denominator;
  return frac_reduce(f);
}

// divides fraction f by fraction d and returns the result in lowest terms
fraction frac_div(fraction f, fraction d) {
  f.numerator *= d.denominator;
  f.denominator *= d.numerator;
  return frac_reduce(f);
}
