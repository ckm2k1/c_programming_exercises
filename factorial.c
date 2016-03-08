#include <stdio.h>

int main() {
  long double input;
  printf("Enter a number: ");
  scanf("%Lf", &input);

  long double sum = 1;
  for (int i = 1; i <= input; ++i) {
    sum *= i;
  }

  printf("%Lg\n", sum);
  return 0;
}