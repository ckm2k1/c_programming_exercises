#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char*, const char*);

int main(int argc, char const *argv[]) {
  test_extension(argv[1], argv[2])
    ? printf("extension match\n")
    : printf("extension doesn't match\n");

  return 0;
}

bool test_extension(const char *filename, const char *ext) {
  const char *extStart = ext;
  while(*ext) ext++;
  while(*filename) filename++;

  while(toupper(*filename) == toupper(*ext)) {
    if (ext == extStart) return true;
    filename--, ext--;
  }

  return false;
}