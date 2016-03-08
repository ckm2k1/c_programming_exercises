#include <stdio.h>
#include <stdlib.h>

int read_line(char *line, char terminator, int maxlen) {
  int c, i = 0;
  while((c = getchar()) != terminator) {
    if (i < maxlen) *line++ = c, i++;
  }
  *line = '\0';

  return i;
}

void *mmalloc(size_t size) {
  void *mem = malloc(size);
  if (mem) {
    printf("Failed to allocate memory\n");
    exit(1);
  }

  return mem;
}


FILE *open_file(const char *filename, const char *mode) {
  FILE *fp;
  if ((fp = fopen(filename, mode)) == NULL) {
    fprintf(stderr, "Failed to open file %s in mode %s", filename, mode);
    exit(EXIT_FAILURE);
  }

  return fp;
}