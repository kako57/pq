#include "fraction.h"
#include "fraction_list.h"
#include "polynomial.h"
#include "solution.h"
#include "int_list.h"
#include <string.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [coefficients in decreasing power]\n", argv[0]);
    return 1;
  }

  polynomial p = {.degree = argc - 2};

  p.coefficients = (fraction *)malloc((p.degree + 1) * sizeof(fraction));

  for (int i = p.degree; i >= 0; i--) {
    char *num = strtok(argv[p.degree - i + 1], "/");
    char *den = strtok(NULL, "/");

    p.coefficients[i].numerator = atoi(num);
    p.coefficients[i].denominator = den == NULL ? 1 : atoi(den);

  }

  solution_node *results = solve(&p);

  puts("Rational roots:");
  printSolutionSet(results);

  deleteSolutionSet(results);
  free(p.coefficients);
}
