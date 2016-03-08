#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  while(argc-- && argc >= 1) printf("%s ", argv[argc]);
  return 0;
}