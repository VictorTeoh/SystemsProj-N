#include "shell.h"


char **parse_args( char *line){
  char **args = malloc(6 * sizeof(char *)); //allocate space for 5 arguments and a null terminator
  int count = 0;
  char *arg;
  while (arg=strsep(&line, " ")){ //check if any delimeters remain
    args[count] = arg; //assign next argument to separated arg
    printf("args[%d] = %s\n", count, args[count++]); //increments count after printing
  }
  args[count] = NULL; //null terminate the array
  return args;
}

int main(){

  /*
  char cmd1[16] = "ls -a -l";
  printf("\nExecuting: %s\n", cmd1);
  char **args = parse_args( cmd1);
  execvp(args[0], args);

  char cmd2[16] = "ps -A";
  printf("\nExecuting: %s\n", cmd2);
  args = parse_args( cmd2);
  //execvp(args[0], args);
  */

  return 0;

}
