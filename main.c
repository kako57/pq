#include "fraction.h"
#include "fraction_list.h"
#include "polynomial.h"
#include "solution.h"
#include "int_list.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s degree [coefficients]\n", argv[0]);
    return 1;
  }

  polynomial p = {.degree = atoi(argv[1])};

  if (argc - 3 != p.degree) {
    fprintf(stderr, "Error: not enough coefficients\n");
    return 1;
  }
  p.coefficients = (int *)malloc((p.degree + 1) * sizeof(int));

  for (int i = p.degree; i >= 0; i--) {
    p.coefficients[i] = atoi(argv[p.degree - i + 2]);
  }

  solution_node *results = solve(&p);

  puts("Rational roots:");
  printSolutionSet(results);

  deleteSolutionSet(results);
  free(p.coefficients);
}
