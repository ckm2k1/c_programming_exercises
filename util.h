#define len(a) (sizeof(a) / sizeof(a[0]))

int read_line(char *line, char terminator, int maxlen);
void *mmalloc(size_t size);

FILE *open_file(const char *filename, const char *mode);