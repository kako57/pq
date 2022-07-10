#include "solution.h"
#include "fraction_list.h"
#include "int_list.h"

solution_node *newSolution(fraction f) {
  solution_node *new_node = (solution_node *)calloc(1, sizeof(solution_node));
  new_node->value = f;
  return new_node;
}

solution_node *insertSolution(solution_node *root, solution_node *new_node) {
  if (root == NULL)
    return new_node;

  if (frac_less(root->value, new_node->value))
    root->left = insertSolution(root->left, new_node);
  else if (frac_greater(root->value, new_node->value))
    root->right = insertSolution(root->right, new_node);
  else
    free(new_node);

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
  while (eq->degree > 0 && eq->coefficients[eq->degree].numerator == 0) eq->degree--;

  // if a_0 is zero, then eq is divisible by x
  while (eq->degree > 0 && eq->coefficients[0].numerator == 0) {
    fraction zero = { 0, 1 };
    solution_node *zero_sol = newSolution(zero);
    // zero won't actually be added if it is there already
    roots = insertSolution(roots, zero_sol);
    fraction *new_coefficients = (fraction *)malloc((eq->degree) * sizeof(fraction));
    for (int i = 0; i < eq->degree; i++)
      new_coefficients[i] = eq->coefficients[i + 1];
    free(eq->coefficients);
    eq->coefficients = new_coefficients;
    eq->degree--;
  }

  if (eq->degree == 0)
    return NULL;

  fraction_node *ps = frac_factors(eq->coefficients[0]);
  fraction_node *qs = frac_factors(eq->coefficients[eq->degree]);

  for (fraction_node *p = ps; p != NULL; p = p->next) {
    for (fraction_node *q = qs; q != NULL; q = q->next) {
      fraction f = frac_div(p->value, q->value);
      if (eval(eq, f).numerator == 0)
        roots = insertSolution(roots, newSolution(f));
    }
  }

  delete_fractions(ps);
  delete_fractions(qs);

  return roots;
}
