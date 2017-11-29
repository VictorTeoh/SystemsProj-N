#include "util.h"

void parse_args( char **args, char *line ){
  int count = 0;
  char *arg;
  while (arg = strsep(&line, " ")){ //check if any delimeters remain
    args[count] = arg; //assign next argument to separated arg
    count++;
  }
  args[count] = NULL; //null terminate the array

}

void parse_commands( char **commands, char *line ){
  int count = 0;
  char *command;
  while (command = strsep(&line, ";")){ //check if any delimeters remain
    strstrip(command);
    commands[count] = command; //assign next argument to separated arg
    count++;
  }
  commands[count] = NULL; //null terminate the array

}

int redirect_stdin(char **args) {
  int i;
  int backup = dup(1);

  for (i = 0; args[i]; i++) {
    if (args[i][0] == '<') {
      char *filename = args[i+1];
      int f = open(filename, O_RDONLY);
      dup2(f, 0);
      close(f);
      args[i] = 0;
    }
  }

  return backup;
}

int redirect_stdout(char **args) {
  int i;
  int backup = dup(1);

  for (i = 0; args[i]; i++) {
    int f;

    if (args[i][0] == '>') {
      char *filename = args[i+1];
      f = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0664);
      dup2(f, 1);
      close(f);
      args[i] = 0;
    }
  }

  return backup;
}

int execute( char *file, char **argv ) {
  int f;

  f = fork();

  if (!f) {
    execvp(file, argv);
    printf("sh: command not found: %s\n", file);
    exit(1);
  }

  int status;
  wait(&status);

  return 0;

}

void getctime(char *buffer, size_t size) {
  struct tm *info;
  time_t rawtime;

  time( &rawtime );
  info = localtime( &rawtime );

  strftime(buffer, size, "%H:%M:%S", info);

}

void strstrip(char *s) {
  size_t size;
  char *end;

  size = strlen(s);

  if (!size)
    return;

  end = s + size - 1;
  while (end >= s && *end == ' ') {
    end--;

  }
  *(end + 1) = '\0';

  while (*s && isspace(*s)) {
    strcpy(s, s+1);

  }
}
