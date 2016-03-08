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

  long long int count = 1;
  int ch;
  while((ch = fgetc(fp)) != EOF) if (ch == '\n') ++count;

  printf("The file contains %lld lines", count);

  return 0;
}