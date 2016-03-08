#include <stdio.h>
#include <stdlib.h>
#include "inv.h"


int main(int argc, char const *argv[]) {
  Part inventory[MAX_PARTS];
  FILE *inventory_file;
  if ((inventory_file = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Could not open inventory file %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  fread(inventory, sizeof(Part), MAX_PARTS, inventory_file);

  printf("%-8s%-20s%7s\n", "Number", "Name", "On hand");
  printf("%s\n", "-------------------------------------\n");
  for (int i = 0; i < MAX_PARTS; ++i) {
    printf("%-8d%-20s%2d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
  }

  fclose(inventory_file);
  return 0;
}