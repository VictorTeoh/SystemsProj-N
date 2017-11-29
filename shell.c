#include "shell.h"
#include "util.h"

void print_prompt() {
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

  printf("# " BLUE "%s " RESET "@ " GREEN "%s" RESET " in " YELLOW "%s " RESET "[%s]\n", user, hostname, cwd, time);
  printf("$ ");
}


int main() {

  /* Initialize shell with clear command */
  char *init_args[2];
  parse_args(init_args, "clear");
  execute(init_args[0], init_args);

  /* Run shell */
  while(1) {
    char buffer[512];

    print_prompt();

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = 0;

    char *commands[10];
    parse_commands(commands, buffer);

    int i = 0;
    while (commands[i] != NULL) {
      char *args[10];
      parse_args(args, commands[i]);

      redirect_stdin(args);
      if (redirect_stdout(args)) {}

      else if (strcmp(args[0], "exit") == 0) {
        // TODO: if there are still tasks, tell user tasks are still running
        return 0;
      }

      else if (strcmp(args[0], "cd") == 0) {
        chdir(args[1]);
      }

      else if (strcmp(args[0], "cwd") == 0) {
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
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
