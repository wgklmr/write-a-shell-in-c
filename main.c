#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_line() {
  int c;
  int position = 0;
  int buffer_size = 1024;
  char *buffer = malloc(buffer_size);

  do {
    c = getchar();

    if (c == '\n') {
      return buffer;
    }

    buffer[position] = c;
    position++;
  } while (1);
}

// Use only whitespace to separate arguments
char **split_line(char *line) {
  int position = 0;
  char **tokens = malloc(1024);
  char *token;

  token = strtok(line, " ");

  while (token != NULL) {
    tokens[position] = token;
    position++;

    token = strtok(NULL, " ");
  }

  return tokens;
}

int launch(char **args) {
  int status;
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    // child process
    execvp(args[0], args);
  } else {
    // parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int cd(char **args) {
  if (chdir(args[1]) != 0) {
    perror("error!!!");
  }

  return 1;
}

int exit_from_sh(void) {
  return 0;
}

int execute(char **args) {
  if (strcmp(args[0], "cd") == 0) {
    return cd(args);
  }

  if (strcmp(args[0], "exit") == 0) {
    return exit_from_sh();
  }

  return launch(args);
}

void loop(void) {
  int status;
  int c;
  char *line;
  char **args;

  do {
    printf("> ");

    // Read
    line = read_line();

    // Parse
    args = split_line(line);

    // Execute
    status = execute(args);

  } while(status);
}

int main(int argc, char **argv) {
   // Load config files, if any.

   // Run command loop.
  loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
