#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lsh_loop(void) {
  int status;
  int c;

  do {
    printf("user > ");
    c = getchar();
    status = 1;
  } while(status);
}

int main(int argc, char **argv) {
  lsh_loop();

  return EXIT_SUCCESS;
}
