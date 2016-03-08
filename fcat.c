#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;

  for(int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("No bueno");
      exit(EXIT_FAILURE);
    }

    int ch;
    while((ch = fgetc(fp)) != EOF) {
      putchar(ch);
    }

    fclose(fp);
  }

  return 0;
}