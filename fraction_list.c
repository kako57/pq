#include "fraction_list.h"

fraction_node *insertFraction(fraction_node *head, fraction value) {
  fraction_node *new_node = (fraction_node *)malloc(sizeof(fraction_node));
  new_node->value = value;
  new_node->next = head;
  return new_node;
}

fraction_node *deleteFractions(fraction_node *head) {
  while (head != NULL) {
    fraction_node *tmp = head;
    head = head->next;
    free(tmp);
  }
  return NULL;
}
