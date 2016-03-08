#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long int ishex(const char *str, size_t len) {
  long int total = 0;
  // point to the end of the string.
  str = str + len - 1;

  for(int i = 0; i < len; i++, str--) {
    if (isxdigit(*str)) {
      if (isdigit(*str)) total += pow(16, i) * atoi(str);
      else {
        total += pow(16, i) * (toupper(*str) - 55);
      }

      continue;
    }

    printf("Invalid hex value");
    return -1;
  }

  return total;
}

int main(int argc, char const *argv[]) {
  long int val = ishex(argv[1], strlen(argv[1]));

  if (val == -1) printf("Invalid hex value");
  else printf("The number is: %ld", val);

  return 0;
}