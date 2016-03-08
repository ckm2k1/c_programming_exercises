#include <stdio.h>

#define MAX 30

int main(int argc, char const *argv[]) {
  printf("Message: \n");
  char c;
  int len = 0;
  char a[MAX];
  char *p = a;
  while((c = getchar()) != '\n') {
    if (len++ == MAX) break;
    *p = c;
    p++;
  }

  while(p != a) printf("%c", *--p);

  return 0;
}