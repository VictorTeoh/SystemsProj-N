#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#define BOLD       "\x1b[1m"
#define RED        "\x1b[31m"
#define GREEN      "\x1b[32m"
#define YELLOW     "\x1b[93m"
#define BLUE       "\x1b[34m"
#define CYAN       "\x1b[36m"
#define LIGHT_BLUE "\x1b[94m"
#define LIGHT_GRAY "\x1b[37m"
#define RESET      "\x1b[0m"

/*======== void print_prompt() ==========
   Inputs: none
   Returns: none

   Prints the prompt after each command
   The prompt features the user name (!!!), hostname, the cwd, and time in color
   Styling is based off of zsh ys theme
   ====================*/
void print_prompt();

/*======== int main() ==========
  Inputs: none
  Returns: int

  Main shell execution function
  ====================*/
int main();
