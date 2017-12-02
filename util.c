#include "util.h"

void parse_args( char **args, char *line ){
  int count = 0;
  while (line){ //check if any delimeters remain
    args[count] = strsep(&line, " "); //assign next argument to separated arg
    count++;
  }
  args[count] = NULL; //null terminate the array

}

void parse_commands( char **commands, char *line ){
  int count = 0;
  while (line){ //check if any delimeters remain
    char *command = strsep(&line, ";");
    strstrip(command);
    commands[count] = command; //assign next argument to separated arg
    count++;
  }
  commands[count] = NULL; //null terminate the array

}

void redirect_stdin(char **args) {
  int i;

  for (i = 0; args[i]; i++) {
    if (args[i][0] == '<') {
      char *filename = args[i+1];
      int f = open(filename, O_RDONLY);
      dup2(f, 0);
      close(f);
      args[i] = 0;
    }
  }
}

void redirect_stdout(char **args) {
  int i;

  for (i = 0; args[i]; i++) {
    int f;
    char *filename;

    if (args[i][0] == '>') {
      if (strlen(args[i]) >= 2 && args[i][1] == '>') {
        // append
        filename = args[i+1];
        f = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0664);
        dup2(f, 1);
        close(f);
        args[i] = 0;
      }
      else {
        filename = args[i+1];
        f = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0664);
        dup2(f, 1);
        close(f);
        args[i] = 0;
      }
    }
  }
}

void pipe_(char **args) {
  int i, l;
  for (i = 0; args[i]; i++) {
    if (args[i][0] == '|') {
      
      char first[256] = "";
      for(l = 0; l < i; l++){
	strcat(first, args[l]);
	strcat(first, " ");
	printf("%s", first);
      }
      
      FILE *fp = popen(first, "r");
      int f = fileno(fp);
      dup2(f, 0);
      close(f);
      args += i + 1;
      execvp(args[0], args); 
    }
  }
}

void run_command( char *buffer ) {
  char *commands[10];
  parse_commands(commands, buffer);

  int i = 0;
  while (commands[i] != NULL) {
    char *args[10];
    parse_args(args, commands[i]);

    if (strcmp(args[0], "exit") == 0) {
      // TODO: if there are still tasks, tell user tasks are still running
      exit(0);
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

int execute( char *file, char **argv ) {
  if (strcmp(file,"") == 0) {
    return 0;
  }

  int f;

  f = fork();

  if (!f) {
    redirect_stdin(argv);
    redirect_stdout(argv);
    pipe_(argv);
    execvp(file, argv);
    printf("%s\n", file);
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
