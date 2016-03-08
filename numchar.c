#include <stdio.h>
#include <string.h>

long int numchar(const char *str, int c);

int main(int argc, char const *argv[]) {
  const char *str = argv[1];
  long int res = numchar(str, *argv[2]);
  printf("Found occur: %ld\n", res);

  return 0;
}

long int numchar(const char *str, int c) {
  long int count = 0;
  for (;(str = strchr(str, c)); str++, count++);
  return count;
}