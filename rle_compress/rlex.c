#include <stdio.h>
#include <stdlib.h>
#include "../util.h"

int main(int argc, char const *argv[]) {
  FILE *in = open_file(argv[1], "rb");
  FILE *out = open_file(argv[2], "wb");

  char count = 0;
  char ch;

  while(fread(&count, sizeof(count), 1, in)) {
    fread(&ch, sizeof(ch), 1, in);

    for(int i = 0; i < count; i++) {
      fwrite(&ch, sizeof(ch), 1, out);
    }
  }

  fclose(in);
  fclose(out);

  return 0;
}