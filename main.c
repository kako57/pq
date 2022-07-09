#include <string.h>

#include "fraction.h"
#include "fraction_list.h"
#include "polynomial.h"
#include "solution.h"
#include "int_list.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [coefficients in decreasing power]\n", argv[0]);
    return 1;
  }

  polynomial p = {(fraction *)malloc((argc - 1) * sizeof(fraction)), argc - 2};

  for (int i = p.degree; i >= 0; i--) {
    char *num = strtok(argv[p.degree - i + 1], "/");
    char *den = strtok(NULL, "/");

    p.coefficients[i] = (fraction){ strtol(num, NULL, 10), den == NULL ? 1 : strtol(den, NULL, 10) };
  }

  solution_node *results = solve(&p);

  puts("Rational roots:");
  printSolutionSet(results);

  deleteSolutionSet(results);
  free(p.coefficients);
}
