#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char word[20] = { '\0' };
  char longest_word[20] = { '\0' };
  char smallest_word[20] = { '\0' };

  while (strlen(word) != 4) {
    printf("Enter a word: ");
    scanf("%s", word);

    if (strcmp(word, longest_word) > 0) {
      strcpy(longest_word, word);
      continue;
    }

    if (strcmp(word, smallest_word) < 0 || smallest_word[0] == 0) {
      strcpy(smallest_word, word);
      continue;
    }
  }

  printf("Longest word: %s\nShortest word: %s", longest_word, smallest_word);

  return 0;
}