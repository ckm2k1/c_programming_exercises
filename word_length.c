#include <stdio.h>

int main() {
  char c;
  int wordLengths = 0, wordCount = 0;

  while((c = getchar())) {
    if (c == '\n') break;

    if (c == ' ' || c == '.') {
      ++wordCount;
      continue;
    }
    ++wordLengths;
  }
  printf("%d %d\n", wordLengths, wordCount);

  printf("The average word length is: %f\n", (float) wordLengths / wordCount);
  return 0;
}