#include "int_list.h"

// insert an int_node at the head of the list
int_node *insert_int(int_node *head, int value) {
  int_node *new_node = (int_node *)malloc(sizeof(int_node));
  new_node->value = value;
  new_node->next = head;
  return new_node;
}

// clear the int_node linked list
int_node *delete_ints(int_node *head) {
  while (head != NULL) {
    int_node *tmp = head;
    head = head->next;
    free(tmp);
  }
  return NULL;
}

// get all the factors of num and store return the result as a linked list
int_node *int_factors(int num) {
  int_node *results = NULL;
  if (num == 0)
    return insert_int(results, 0);

  if (num < 0)
    num *= -1;

  for (int i = 1; i <= num; i++)
    if (num % i == 0)
      results = insert_int(insert_int(results, -i), i);

  return results;
}

