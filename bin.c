#include <stdio.h>

void print_binary(int n);

int main(int argc, char const *argv[])
{
  int in = 0;
  scanf("%d", &in);
  print_binary(in);
  return 0;
}

void print_binary(int n) {
  if (n != 0) {
    print_binary(n / 2);
    putchar('0' + n % 2);
  }
}