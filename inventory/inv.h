#ifndef INV_H
#define INV_H

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} Part;

#endif

