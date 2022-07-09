#include <stdlib.h>
#include <assert.h>
#ifndef _INT_LIST_H

typedef struct __int_node {
  int value;
  struct __int_node *next;
} int_node;

int_node *insert_int(int_node *head, int value);
int_node *delete_ints(int_node *head);
int_node *int_factors(int num);

#define _INT_LIST_H
#endif
