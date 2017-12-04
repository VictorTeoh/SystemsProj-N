
# cshell

by Ryan Siu and Victor Teoh

## Features
- Forks and executes commands!  
- Parses multiple commands separated by semicolons  
- Redirects stdout, and stdin using >, < respectively 
- Simple piping

## Attempted
- Tried replacing ~/ with home directory

## Bugs
	
## Files & Function Headers

### shell.c
- Main shell execution file
	```
	/*======== void print_prompt() ==========
	Inputs: none
	Returns: none

	Prints the prompt after each command
	The prompt features the user name (!!!), hostname, the cwd, and time in color
	Styling is based off of zsh ys theme
	====================*/
	
	/*======== int main() ==========
	Inputs: none
	Returns: int

	Main shell execution function
	====================*/
	```

### util.c
- Handles line parsing
- Handles command execution, including piping and redirection
- Utility functions

	```
	/*======== void strstrip( char * ) ==========
	Inputs:  char *s 
	Returns: none

	Removes leading and trailing whitespace on the string line.
	Terminating '\0' is inserted at a new location if necessary.
	====================*/
	
	/*======== void parse_args ( char **, char * ) ==========
	Inputs:  char **commands, char *line
	Returns: none

	If line contains multiple tokens separated by a space, this 
	function will put each token into an array of strings
	====================*/
	
	/*======== void parse_commands ( char **, char * ) ==========
	Inputs:  char **commands, char *line
	Returns: none

	If line contains multiple commands separated by a semicolon, this 
	function will put each token into an array of commands
	====================*/
	
	/*======== void execute ( char *, char ** ) ==========
	Inputs:  char *file, char **argv
	Returns: none

	Forks a child to execute a command
	Redirects stdin/stdout or pipes as necessary
	Error message is printed if command is not found
	Waits for child to finish before exiting the function
	====================*/
	
	/*======== void getctime ( char *, size_t ) ==========
	Inputs:  char *buffer, size_t size
	Returns: none

	Puts the current time as a string in the format (hr:min:sec) into the buffer. 
	====================*/
	
	/*======== void redirect_stdin ( char ** ) ==========
	Inputs:  char **args
	Returns: none

	Redirects stdin from file if < character is in args.
	====================*/
	
	/*======== void parse_commands ( char ** ) ==========
	Inputs:  char **args
	Returns: none

	Redirects stdout to a file if > character is in args
	====================*/
	
	
	/*======== void pipe_ ( char ** ) ==========
	Inputs:  char **args
	Returns: none

	Redirect stdout from one command to stdin of the next
	====================*/
	
	/*======== void run_command ( char * ) ==========
	Inputs:  char *buffer
	Returns: none

	Runs a command
	====================*/
	
	```
