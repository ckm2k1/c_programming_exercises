#include <stdio.h>
#include "util.h"

int main() {

  char c;
  char open[100];
  int index = 0;

  while((c = getchar()) != '\n') {
    switch(c) {
      case '{':
      case '[':
      case '(':
        open[index++] = c;
        break;

      case '}':
      case ']':
      case ')':
        open[--index] = NULL;
        break;
    }
  }

  if (index) {
    printf("You have an unclosed bracket");
  } else {
    printf("All good");
  }

  return 0;
}