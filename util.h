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

/*======== void strstrip( char * ) ========
  Inputs:  char *s
  Returns: none

  Removes leading and trailing whitespace on the string line.
  Terminating '\0' is inserted at a new location if necessary.
  ====================*/
void strstrip(char *);

/*===== void parse_args ( char **, char * ) ======
  Inputs:  char **commands, char *line
  Returns: none

  If line contains multiple tokens separated by a space, this
  function will put each token into an array of strings
  ====================*/
void parse_args( char **, char * );

/*======== void parse_commands ( char **, char * ) ==========
  Inputs:  char **commands, char *line
  Returns: none

  If line contains multiple commands separated by a semicolon, this
  function will put each token into an array of commands
  ====================*/
void parse_commands( char **, char * );

/*======== void execute ( char *, char ** ) ==========
  Inputs:  char *file, char **argv
  Returns: none

  Forks a child to execute a command
  Redirects stdin/stdout or pipes as necessary
  Error message is printed if command is not found
  Waits for child to finish before exiting the function
  ====================*/
void execute( char *, char ** );

/*======== void getctime ( char *, size_t ) ==========
  Inputs:  char *buffer, size_t size
  Returns: none

  Puts the current time as a string in the format (hr:min:sec) into the buffer.
  ====================*/
void getctime( char *, size_t );

/*======== void redirect_stdin ( char ** ) ==========
  Inputs:  char **args
  Returns: none

  Redirects stdin from file if < character is in args.
  ====================*/
void redirect_stdin( char ** );

/*======== void parse_commands ( char ** ) ==========
  Inputs:  char **args
  Returns: none

  Redirects stdout to a file if > character is in args
  ====================*/
void redirect_stdout( char ** );

/*======== void pipe_ ( char ** ) ==========
  Inputs:  char **args
  Returns: none

  Redirect stdout from one command to stdin of the next
  ====================*/
void pipe_(char ** );

/*======== void run_command ( char * ) ==========
  Inputs:  char *buffer
  Returns: none

  Runs a command
  ====================*/
void run_command( char * );

#endif
