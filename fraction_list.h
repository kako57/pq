#include <stdlib.h>

#ifndef _FRACTION_LIST_H
#include "fraction.h"
typedef struct __fraction_node {
  fraction value;
  struct __fraction_node *next;
} fraction_node;

fraction_node *insert_fraction(fraction_node *head, fraction value);
fraction_node *delete_fractions(fraction_node *head);
fraction_node *frac_factors(fraction f);

#define _FRACTION_LIST_H
#endif
