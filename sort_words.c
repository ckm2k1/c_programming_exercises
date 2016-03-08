#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int read_line(char *line, char terminator, int maxlen) {
  int c, i = 0;
  while((c = getchar()) != terminator) {
    if (i < maxlen) *line++ = c, i++;
  }
  *line = '\0';

  return i;
}

struct vstring {
  int len;
  char *str[];
};

int compar(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int main() {
  char word[20];
  char **words = malloc(sizeof(char *) * 20);
  int word_count = 0;

  int read = 0;
  for(;;) {
    if (isatty(fileno(stdin)))
      printf("Enter a word: ");

    if(!(read = read_line(word, '\n', 20))) break;


    if (word_count == 20) {
      words = realloc(words, sizeof(char *) * word_count * 2);
      if (!words) exit(1);
    }

    words[word_count] = malloc(strlen(word) + 1);
    strcpy(words[word_count++], word);
  }

  qsort(words, word_count, sizeof(char *), compar);

  printf("\n\n\nSorted words: ");
  for(int i = 0; i < word_count; i++) {
    printf("%s", words[i]);
    printf("%s", i == word_count - 1 ? "": ", ");
    printf("%s", !(i % 5) ? "\n" : "");
  }

  return 0;
}