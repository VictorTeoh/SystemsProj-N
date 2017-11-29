#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <ctype.h>

#ifndef UTIL_H
#define UTIL_H
void strstrip(char *);
void parse_args( char **, char * );
void parse_commands( char **, char * );
int execute( char *, char ** );
void getctime( char *, size_t );
char * get_prompt();
#endif