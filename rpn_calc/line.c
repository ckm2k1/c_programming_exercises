#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

typedef struct node {
  char *word;
  struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
  if (!head) return;

  node *cur = head;
  do {
    node *tmp = cur;
    cur = cur->next;
    free(tmp->word);
    free(tmp);
  } while(cur != NULL);

  head = NULL;
  tail = head;
  num_words = 0;
  line_len = 0;
}

void add_word(const char *word) {
  node *new = malloc(sizeof(struct node));
  new->word = malloc(strlen(word) + 1);
  strcpy(new->word, word);
  new->next = NULL;

  if (!head) {
    head = new;
    tail = head;
  }
  else {
    tail->next = new;
    tail = new;
  }

  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) {
  return MAX_LINE_LEN - line_len;
}

void write_line(void) {
  int extra_spaces, spaces_to_insert, i, j, words;
  words = num_words;

  extra_spaces = MAX_LINE_LEN - line_len;

  node *cur = head;
  for(; cur != NULL; cur = cur->next) {
    printf("%s", cur->word);

    spaces_to_insert = extra_spaces / (num_words);
    for (j = 1; j <= spaces_to_insert + 1; j++) {
      putchar(' ');
    }
    extra_spaces -= spaces_to_insert;
    num_words--;

    // cur = cur->next;
  }
  // printf("%s", cur->word);

  printf(" -- line has %d words and %d chars", words, line_len);
  putchar('\n');
}

void flush_line(void) {
  if (line_len > 0) {
    write_line();
  }
}