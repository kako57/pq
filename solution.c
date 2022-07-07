#include "solution.h"
#include "int_list.h"

solution_node *newSolution(fraction f) {
  solution_node *new_node = (solution_node *)calloc(1, sizeof(solution_node));
  new_node->value = f;
  return new_node;
}

solution_node *insertSolution(solution_node *root, solution_node *new_node) {
  if (root == NULL) {
    return new_node;
  }

  if (frac_less(root->value, new_node->value)) {
    root->left = insertSolution(root->left, new_node);
  } else if (frac_greater(root->value, new_node->value)) {
    root->right = insertSolution(root->right, new_node);
  } else {
    free(new_node);
  }

  return root;
}

solution_node *deleteSolutionSet(solution_node *root) {
  if (root == NULL)
    return NULL;
  root->left = deleteSolutionSet(root->left);
  root->right = deleteSolutionSet(root->right);
  free(root);
  return NULL;
}

void printSolutionSet(solution_node *root) {
  if (root == NULL)
    return;
  printSolutionSet(root->left);
  print_fraction(root->value);
  printSolutionSet(root->right);
}

solution_node *solve(polynomial *eq) {
  // p is a factor of a_0
  // q is a factor of a_{n-1}
  solution_node *roots = NULL;

  // if the degree stated is greater what it actually seems
  while (eq->coefficients[eq->degree] == 0) {
    eq->degree--;
  }

  // if a_0 is zero, then eq is divisible by x
  while (eq->coefficients[0] == 0) {
    fraction zero = { 0, 1 };
    solution_node *zero_sol = newSolution(zero);
    // zero won't actually be added if it is there already
    roots = insertSolution(roots, zero_sol);
    int *new_coefficients = (int *)malloc((eq->degree) * sizeof(int));
    for (int i = 0; i < eq->degree; i++)
      new_coefficients[i] = eq->coefficients[i + 1];
    free(eq->coefficients);
    eq->coefficients = new_coefficients;
    eq->degree--;
  }

  int_node *ps = find_factors(eq->coefficients[0]);
  int_node *qs = find_factors(eq->coefficients[eq->degree]);

  for (int_node *p = ps; p != NULL; p = p->next) {
    for (int_node *q = qs; q != NULL; q = q->next) {
      fraction f = { p->value, q->value };
      f = frac_reduce(f);
      
      fraction result = eval(eq, f);
      if (result.numerator == 0) {
        solution_node *new_sol = newSolution(f);
        roots = insertSolution(roots, new_sol);
      }
    }
  }

  deleteInts(ps);
  deleteInts(qs);

  return roots;
}

