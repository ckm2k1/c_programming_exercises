#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
  void *value;
  Node next;
};

struct stack_type {
  Node top;
  Node tail;
  size_t len;
};


static void terminate(const char *msg) {
  printf("%s\n", msg);
  exit(1);
}

Stack create(void) {
  Stack s = malloc(sizeof(Stack));
  if (!s) terminate("Could not allocate space for Stack");

  s->top = malloc(sizeof(Node));
  s->top->next = NULL;
  s->tail = s->top;
  s->len = 0;


  return s;
}

void destroy(Stack s) {

}

void make_empty(Stack s) {

}

bool is_empty(Stack s) {
  return (s->top->next == NULL);
}

bool is_full(Stack s) {
  return false;
}

void push(Stack s, void *value) {
  Node n = malloc(sizeof(Node));
  if (!n) terminate("Failed to allocate memory for Node in push()");

  n->value = value;

  // point new node to the current
  // top of stack.
  n->next = s->top;

  //point top to new node
  s->top = n;
  s->len++;
}

size_t len(Stack s) {
  return s->len;
}

void *pop(Stack s) {
  Node n = s->top;
  void *value = n->value;

  // point the top to
  // the next value down.
  s->top = n->next;
  // free the node
  free(n);
  s->len--;

  return value;
}