#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char *line, char terminator, int maxlen) {
  int c, i = 0;
  while((c = getchar()) != terminator) {
    if (i < maxlen) *line++ = c, i++;
  }
  *line = '\0';

  return i;
}

void print_reminders(char (*reminders)[MSG_LEN], size_t len) {
  int i;
  for(i = 0; i < len; i++) {
    printf("%s\n", reminders++);
  }
}

int main(int argc, char const *argv[]) {
  char *prompt = "Enter day and reminder: ";
  char line[MSG_LEN];
  char reminders[MAX_REMIND][MSG_LEN];
  size_t num_remind = 0;

  while(1) {
    int day;

    if (num_remind == MAX_REMIND) break;

    printf("%s", prompt);
    scanf("%2d", &day);

    if (day == 0) break;

    read_line(line, '\n', MSG_LEN);
    strcpy(reminders[num_remind++], line);
  }

  print_reminders(reminders, num_remind);

  return 0;
}