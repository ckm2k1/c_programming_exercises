#include <stdio.h>
#include <stdlib.h>
#include "../util.h"


int main(int argc, char const *argv[]) {
  FILE *in = open_file(argv[1], "rb");
  char *out_filename;
  asprintf(&out_filename, "%s.rle", argv[1]);
  FILE *out = open_file(out_filename, "wb");

  char count = 1;
  char previous, current;
  size_t read;

  read = fread(&previous, sizeof(previous), 1, in);
  if (read) {
    while(1) {
      read = fread(&current, sizeof(current), 1, in);
      if (current == previous && read) count++;
      else {
        fwrite(&count, sizeof(count), 1, out);
        fwrite(&previous, sizeof(previous), 1, out);
        count = 1;
        if (!read) break;
      }
      previous = current;
    }
  }

  free(out_filename);
  fclose(in);
  fclose(out);

  return 0;
}