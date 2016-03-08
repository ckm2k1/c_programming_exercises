#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int c;
  bool wasSpace = true;

  while((c = getchar()) != EOF) {
    if (isspace(c)) { wasSpace = true; }
    if (isalpha(c) && wasSpace) {
      c = toupper(c);
      wasSpace = false;
    }
    putchar(c);
  }
  return 0;
}