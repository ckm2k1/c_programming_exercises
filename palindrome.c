#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  #define MAX 100

  char m[MAX];
  char *e = m, *b = m;
  int len = 0;

  while((*e++ = getchar()) != '\n' && len++ < MAX);

  printf("%s\n", m);
  while(b <= e) {
    if (!isalpha(*b)) { ++b; continue; }
    if (!isalpha(*e)) { --e; continue; }
    if (toupper(*e) != toupper(*b)) { printf("\nNot a palindrome..."); return 0; }
    b++, e--;
  }

  printf("\nThe setnence is a palindrome!");

  return 0;
}