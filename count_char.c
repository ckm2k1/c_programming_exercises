#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("missing file arg");
    exit(EXIT_FAILURE);
  }

  long long int count = 0;
  while(fgetc(fp) != EOF) count++;

  printf("The file contains %lld characters", count);

  return 0;
}