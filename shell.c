#include "shell.h"
#include "util.h"

void print_prompt() {
  char user[256];
  char hostname[256];
  char cwd[256];
  char time[16];

  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw) {
    strcpy(user, pw->pw_name);
  } else {
    strcpy(user, "user");
  }

  gethostname(hostname, sizeof(hostname));
  getcwd(cwd, sizeof(cwd));
  getctime(time, sizeof(time));

  // could use this to implement ~ if we could replace strings
  // char *HOME_DIR = getenv("HOME");

  printf(LIGHT_BLUE "# " CYAN "%s " RESET "@ " GREEN "%s" RESET " in " YELLOW BOLD "%s " RESET LIGHT_GRAY "[%s]" RESET " SHELL\n", user, hostname, cwd, time);
  printf(RED BOLD "$ " RESET);
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

    run_command( buffer );
  }

  return 0;
}
