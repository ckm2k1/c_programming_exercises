#include <stdio.h>

int main(int argc, char const *argv[])
{
  int numDays = 30, startDay = 1;

  printf("Enter the the number of days in the month: ");
  scanf("%d", &numDays);

  printf("\nEnter starting day of the week: ");
  scanf("%d", &startDay);

  for (int i = 0; i <= numDays; ++i) {
    if (i >= startDay) printf("%2d ", i);
    else printf("%3s", "");
    if (!(i % 7)) printf("\n");
  }

  return 0;
}