#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *line = malloc(200 * sizeof(char));
  char *buffer[200];
  int len = 0;
  size_t line_length = 200;

  printf("Enter a series of words: ");
  int read = getline(&line, &line_length, stdin);
  // remove the newline.
  line[read - 1] = '\0';

  char *chunk = strtok(line, " ");
  if (chunk != NULL) buffer[len++] = chunk;

  while((chunk = strtok(NULL, " ")) != NULL) {
    buffer[len++] = chunk;
  }

  for(len = len - 1; len >= 0; len--) {
    // printf("%d\n", len);
    printf("%s ", buffer[len]);
  }

  return 0;
}