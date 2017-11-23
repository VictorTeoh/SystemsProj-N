#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <ctype.h>

void strstrip(char *);
void parse_args( char **, char * );
int execute( char *, char ** );
void getctime( char *, size_t );
int main();
