#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char const *argv[]) {
  int c;
  bool start = true;

  while((c = getchar()) != EOF) {
    if (isblank(c) && start) continue;
    else if(c == '\n') {
      putchar(c);
      start = true;
    }
    else {
      putchar(c);
      start = false;
    }
  }

  return 0;
}