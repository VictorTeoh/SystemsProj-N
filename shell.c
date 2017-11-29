#include "shell.h"
#include "util.h"

int main() {

  char *init_args[2];
  parse_args(init_args, "clear");
  execute(init_args[0], init_args);

  // TODO: add to history function
  char *history[11];
  history[10] = NULL;

  while(1){
    char buffer[512];

    char user[256];
    char hostname[256];
    char cwd[256];
    char time[16];

    // TODO: user broken?
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
        // if there are still tasks, tell user tasks are still running
        return 0;
      }

      else if (strcmp(args[0], "cd") == 0) {
        chdir(args[1]);
      }

      else if (strcmp(args[0], "cwd") == 0) {
        printf("%s\n", cwd);
      }

      // history, to be implemented
      else if (args[0][0] == '!') {
        char *c = &args[0][1];
        printf("%s\n", c);
      }

      else if (strcmp(args[0], "history") == 0) {
        int j = 0;
        while (history[j]) {
          printf("%s\n", history[j]);
          j++;
        }
      }

      else {
        execute( args[0], args );
      }

      i++;
    }

    printf("\n");
  }

  return 0;
}
