#include "shell.h"

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

void strstrip(char *s)
{
  size_t size;
  char *end;

  size = strlen(s);

  if (!size)
    return;

  end = s + size - 1;
  while (end >= s && isspace(*end)) {
    end--;
  }
  *(end + 1) = '\0';

  while (*s && isspace(*s)) {
    strcpy(s, s+1);
  }
  
}

int main() {

  char *init_args[2];
  parse_args(init_args, "clear");
  execute(init_args[0], init_args);

  while(1){
    char buffer[512];

    char user[256];
    char hostname[256];
    char cwd[256];
    char time[16];

    getlogin_r(user, sizeof(user));
    gethostname(hostname, sizeof(hostname));
    getcwd(cwd, sizeof(cwd));
    getctime(time, sizeof(time));

    // could use this to implement ~ if we could replace strings
    char HOME_DIR[64] = "/home/";
    strcat(HOME_DIR, user);

    printf("# %s @ %s in %s [%s]\n", user, hostname, cwd, time);
    printf("$ ");

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = 0;

    char *commands[10];
    parse_commands(commands, buffer);

    int i = 0;
    while (commands[i] != NULL) {
      char *args[10];
      parse_args(args, commands[i]);

      if (strcmp(args[0], "exit") == 0) {
        return 0;
      }

      else if (strcmp(args[0], "cd") == 0) {
        chdir(args[1]);
      }

      else if (strcmp(args[0], "cwd") == 0) {
        printf("%s\n", cwd);
      }

      else {
        execute( args[0], args );
      }
      
      i++;
    }

    printf("\n");
  }

  
  /*
    char cmd1[16] = "ls -a -l";
    printf("\nExecuting: %s\n", cmd1);
    char **args = parse_args( cmd1);
    execvp(args[0], args);
    /*
    char cmd2[16] = "ps -A";
    printf("\nExecuting: %s\n", cmd2);
    args = parse_args( cmd2);
    //execvp(args[0], args);
    */

  return 0;

}
