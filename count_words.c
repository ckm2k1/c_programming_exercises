#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("missing file arg");
    exit(EXIT_FAILURE);
  }

  long long int count = 0;
  int ch;
  bool start = false;
  while((ch = fgetc(fp)) != EOF) {
    if (isalnum(ch) || isnumber(ch)) start = true;

    if ((isspace(ch) || ispunct(ch)) && start) {
      ++count; start = false;
    }
  }
  if (ch == EOF && start) ++count;

  printf("The file contains %lld words", count);

  return 0;
}