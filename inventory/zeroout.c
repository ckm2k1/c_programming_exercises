#include <stdio.h>
#include <stdlib.h>
#include "inv.h"

Part inventory[MAX_PARTS];
int num_parts;

int main(int argc, char **argv) {
  FILE *fp;
  int i;

  if((fp = fopen(argv[1], "rb+")) == NULL) {
    fprintf(stderr, "Can't open invetory file \n");
    exit(EXIT_FAILURE);
  }

  num_parts = fread(inventory, sizeof(struct part) MAX_PARTS, fp);

  for(i = 0; i < num_parts; i++)
    inventory[i].on_hand = 0;

  rewind(fp);
  fwrite(inventory, sizeof(struct part), num_parts, fp);
  fclose(fp);

  return 0;
}