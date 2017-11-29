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

int execute( char *file, char **argv ) {
  int f;

  f = fork();

  if (!f) {
    execvp(file, argv);

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
