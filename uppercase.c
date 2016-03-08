#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open file");
    exit(EXIT_FAILURE);
  }

  int ch;
  while((ch = fgetc(fp)) != EOF) {
    if (isascii(ch)) printf("%c", toupper(ch));
    else printf("%c", ' ');
  }

  fclose(fp);
  return 0;
}