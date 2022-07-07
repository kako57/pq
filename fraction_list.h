#include <stdlib.h>

#ifndef _FRACTION_LIST_H
#include "fraction.h"
typedef struct __fraction_node {
  fraction value;
  struct __fraction_node *next;
} fraction_node;

#define _FRACTION_LIST_H
#endif
