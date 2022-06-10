#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_line() {
  int c;
  int position = 0;
  int buffer_size = 1024;
  char *buffer = malloc(buffer_size); // 確保したメモリのポインタを返す

  do {
    c = getchar();

    if (c == '\n') {
      return buffer;
    }

    buffer[position] = c;
    position++;
  } while (1);
}

void lsh_loop(void) {
  int status;
  int c;
  char *line;

  do {
    // Read

    // Parse

    // Execute

    printf("root > ");

    line = read_line();

    printf("%c\n", line[0]);
    printf("%c\n", line[1]);
    printf("%c\n", line[2]);
    printf("%c\n", line[3]);

    // printf("%d\n", line[0]);
    // args = split_line(line);
    // status = execute(args);

  } while(status);
}

int main(int argc, char **argv) {
   // Load config files, if any.

   // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
