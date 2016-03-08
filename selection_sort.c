#include <stdio.h>
#include "util.h"

void selection_sort(int len, int arr[len]);

int main() {
  int in[] = {6, 3, 2466, 53, 345, 56467, 345, 345, 76, 536, 56, 8978, 45, 234, 24, 667, 56, 234, 356, 345};
  selection_sort(len(in), in);

  for (int i = 0; i < len(in); ++i) {
    printf("%d, ", in[i]);
  }

  return 0;
}

void selection_sort(int len, int arr[len]) {
  if (len == 1) return;

  int l = 0;
  for (int i = 0; i < len; ++i) {
    if (arr[i] > arr[l]) l = i;
  }
  int t = arr[len - 1];
  arr[len - 1] = arr[l];
  arr[l] = t;
  selection_sort(len - 1, arr);
}