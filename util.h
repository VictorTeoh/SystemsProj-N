#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <ctype.h>
#include <fcntl.h>

#ifndef UTIL_H
#define UTIL_H
void strstrip(char *);
void parse_args( char **, char * );
void parse_commands( char **, char * );
void execute( char *, char ** );
void getctime( char *, size_t );
char * get_prompt();
void redirect_stdin( char ** );
void redirect_stdout( char ** );
void pipe_(char ** );
void run_command( char * );
#endif
