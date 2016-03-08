#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inv.h"


int main(int argc, char const *argv[]) {
  srand((unsigned int) time(NULL));
  Part inventory[MAX_PARTS];
  FILE *inventory_file;
  if ((inventory_file = fopen(argv[1], "wb")) == NULL) {
    fprintf(stderr, "Could not open file provided");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < MAX_PARTS; ++i) {
    inventory[i].number = i;
    sprintf(inventory[i].name, "%s%d", "partsky", rand());
    inventory[i].on_hand = rand() % 2;
  }

  fwrite(inventory, sizeof(Part), MAX_PARTS, inventory_file);
  fclose(inventory_file);
  return 0;
}