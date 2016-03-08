#include <stdio.h>
#include "stackADT.h"

int main(void) {
  Stack s1, s2;
  int n1 = 1, n2 = 2;

  s1 = create();
  s2 = create();

  push(s1, &n1);

  push(s1, &n2);

  n1 = *(int *)pop(s1);
  printf("Popped %d from stack s1\n", n1);
  printf("The stack has %lu item\n", len(s1));
  // push(s2, n);
  // n = pop(s1);
  // printf("Popped %d from s1\n", n);
  // push(s2, n);

  // destroy(s1);

  // while (!is_empty(s2))
  //   printf("Popped %d from s2\n", pop(s2));

  // push(s2, 3);
  // make_empty(s2);

  // if(is_empty(s2))
  //   printf("s2 is empty\n");
  // else
  //   printf("s2 is not empty\n");

  // destroy(s2);

  return 0;
}