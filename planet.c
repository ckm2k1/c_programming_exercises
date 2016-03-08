#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
  char *planets[] = {
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptune",
    "Pluto"
  };

  int i, z;
  for (i = 1; i < argc; i++) {

    for (z = 0; z < NUM_PLANETS; z++) {
      if (strcmp(argv[i], planets[z]) == 0) {
        printf("%s is planet %d\n", argv[i], z + 1);
        break;
      }
    }

    if (z == NUM_PLANETS) {
      printf("%s is not a planet\n", argv[i]);
    }
  }

  return 0;
}