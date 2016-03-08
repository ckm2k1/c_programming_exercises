#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define width 10

int main(int argc, char const *argv[]) {
  FILE *fp;
  if((fp = fopen(argv[1], "rb")) == NULL) {
    printf("forgot the file arg\n");
    exit(EXIT_FAILURE);
  }

  printf("%6s  %12s%s%12s  %10s\n", "Offset", "", "Bytes", "", "Characters");

  long file_pos = ftell(fp);
  char buff[width] = {'\0'};
  size_t seen = 0;
  while((seen = fread(buff, sizeof(char), sizeof(buff), fp)) != 0) {
    printf("%6ld", file_pos);
    printf("%1s", "");

    for(int i = 0; i < seen; i++) printf(" %02x", buff[i]);
    printf("%2s", "");

    for(int i = 0; i < seen; i++) {
      printf("%-c", isprint(buff[i]) ? buff[i] : '.');
    }
    printf("\n");

    file_pos = ftell(fp);
  }

  return 0;
}