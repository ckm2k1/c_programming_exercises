#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  int month, day, year;

  printf("Enter date: ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("\n%s %d, %d", months[month - 1], day, year);

  return 0;
}