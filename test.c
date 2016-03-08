#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define function_called() printf("%s\n", __func__);

int main(int argc, char const *argv[]) {
  char *str = malloc(50);
  strcpy(str, "This is some kind of string");
  char *buffer[200];
  int len = 0;

  char *chunk = strtok(str, " ");
  if (chunk != NULL) buffer[len++] = chunk;

  while((chunk = strtok(NULL, " ")) != NULL) {
    buffer[len++] = chunk;
  }

  for(--len; len >= 0; len--) printf("%s ", buffer[len]);

  return 0;
}