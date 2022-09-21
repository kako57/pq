#include "fraction_list.h"
#include "int_list.h"

// insert fraction at head of list
fraction_node *insert_fraction(fraction_node *head, fraction value) {
  fraction_node *new_node = (fraction_node *)malloc(sizeof(fraction_node));
  new_node->value = value;
  new_node->next = head;
  return new_node;
}

// delete list of fractions
fraction_node *delete_fractions(fraction_node *head) {
  while (head != NULL) {
    fraction_node *tmp = head;
    head = head->next;
    free(tmp);
  }
  return NULL;
}

// enumerate all possible rational factors of a fraction
fraction_node *frac_factors(fraction f) {
  fraction_node *results = NULL;
  int_node *num_factors = int_factors(f.numerator);
  int_node *den_factors = int_factors(f.denominator);

  for (int_node *i = num_factors; i != NULL; i = i->next) {
    for (int_node *j = den_factors; j != NULL; j = j->next) {
      results = insert_fraction(results, (fraction) {.numerator = i->value, .denominator = j->value});
    }
  }

  delete_ints(num_factors);
  delete_ints(den_factors);

  return results;
}
