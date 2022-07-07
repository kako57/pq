#include <stdlib.h>
#include <assert.h>
#ifndef _INT_LIST_H

typedef struct __int_node {
  int value;
  struct __int_node *next;
} int_node;

int_node *insertInt(int_node *head, int value);
int_node *deleteInts(int_node *head);
int_node *find_factors(int num);

#define _INT_LIST_H
#endif
