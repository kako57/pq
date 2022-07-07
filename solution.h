#include "fraction.h"
#include "polynomial.h"
#include "int_list.h"

#ifndef _SOLUTION_H

typedef struct __solution_node {
  fraction value;
  struct __solution_node *left;
  struct __solution_node *right;
} solution_node;

solution_node *newSolution(fraction f);
solution_node *insertSolution(solution_node *root, solution_node *new_node);
solution_node *deleteSolutionSet(solution_node *root);
void printSolutionSet(solution_node *root);
solution_node *solve(polynomial *eq);

#define _SOLUTION_H
#endif
