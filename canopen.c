#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void e() {
  printf("shit");
  return exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
  int len = argc;
  bool nogo[argc];

  while(--argc) nogo[argc] = (fopen(argv[argc], "r") != NULL);
  while(len > 0) nogo[argc++] ? --len : e();

  return 0;
}