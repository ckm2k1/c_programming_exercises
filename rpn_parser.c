#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "util.h"


/*------------------Stack-------------------*/

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

bool isFull() {
  return top == STACK_SIZE;
}

bool isEmpty() {
  return top == 0;
}

void stackOverflow() {
  printf("Stack overflow!\n");
  exit(1);
}

void stackUnderflow() {
  printf("Stack underflow!\n");
  exit(1);
}

int lastElement() {
  if (isEmpty()) stackOverflow();
  else return stack[top - 1];
}

int pop() {
  if (isEmpty()) stackUnderflow();
  else return stack[--top];
}

void push(int el) {
  if (isFull()) stackOverflow();
  stack[top++] = el;
}

void empty() {
  top = 0;
}

void printStack() {
  printf("stack: ");
  for (int i = 0; i < top; ++i) {
    printf("%d", stack[i]);
  }
}

/*------------------Stack-------------------*/

void prompt() {
  printf("Enter an RPN expression: ");
}

void showTopOfStack() {
  printf("Result of the expression: %d\n", lastElement());
}

void performOp(int op) {
  int a = pop();
  int b = pop();

  switch(op) {
    case '+': push(a + b); break;
    case '-': push(a - b); break;
    case '*': push(a * b); break;
    case '/': push(a / b); break;
  }
}


int main() {
  prompt();

  while(true) {
    char ch;

    scanf(" %c", &ch);

    switch(ch) {
      case '+':
      case '-':
      case '*':
      case '/':
        performOp(ch);
        break;

      case '=':
        showTopOfStack();
        prompt();
        empty();
        break;

      case '1': push(1); break;
      case '2': push(2); break;
      case '3': push(3); break;
      case '4': push(4); break;
      case '5': push(5); break;
      case '6': push(6); break;
      case '7': push(7); break;
      case '8': push(8); break;
      case '9': push(9); break;
      case '0': push(0); break;

      default:
        return 0;
        break;
    }
  }

  return 0;
}



