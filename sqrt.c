#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  double in;

  printf("Enter a number: ");
  scanf("%lf", &in);

  double y = in - 1, prev = in;
  while(fabs(prev - y) > (y * 0.000000001)) {
    printf("%lf %lf\n", prev, y);
    prev = y;
    y = (y + (in / y)) / 2;
  }

  printf("The sqrt of %.2lf is %lf", in, y);

  return 0;
}