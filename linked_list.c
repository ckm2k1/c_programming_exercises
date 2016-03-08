#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

int main(int argc, char const *argv[]) {
  node *head = NULL; //malloc(sizeof(node));
  head->value = 123;

  printf("%d\n", head->value);
  free(head);

  return 0;
}