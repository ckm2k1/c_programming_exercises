#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  long sum = 0;
  while(argc-- && argc >= 1) sum += atoi(argv[argc]);
  printf("Total: %ld\n", sum);
  return 0;
}