#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cd(char **args) {
  if (chdir(args[1]) != 0) {
    perror("error!!!");
  }

  return 1;
}

int exit_from_sh(void) {
  return 0;
}
