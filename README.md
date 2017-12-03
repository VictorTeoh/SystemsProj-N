# Shell name

by Ryan Siu and Victor Teoh

## Features
- Forks and executes commands!  
- Parses multiple commands separated by semicolons  
- Redirects using >, < 

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
	```

### util.c
- Handles all line parsing fucntions

	```
	/*======== void strstrip() ==========
	Inputs:  char *s 
	Returns: none

	Removes leading and trailing whitespace on the string line.
	Terminating '\0' is inserted at a new location if necessary.
	====================*/
	
	/*======== void ** parse_args () ==========
	Inputs:  char **commands, char *line
	Returns: none

	If line contains multiple tokens separated by a space, this 
	function will put each token into an array of strings
	====================*/
	
	/*======== void ** parse_commands () ==========
	Inputs:  char **commands, char *line
	Returns: none

	If line contains multiple commands separated by a semicolon, this 
	function will put each token into an array of commands
	====================*/
	
	/*======== void ** parse_commands () ==========
	Inputs:  char **commands, char *line
	Returns: none

	If line contains multiple commands separated by a semicolon, this 
	function will put each token into an array of commands
	====================*/
	
	/*======== void getctime ( char *, size_t ) ==========
	Inputs:  char *buffer, size_t size
	Returns: none

	Puts the current time as a string in the format (hr:min:sec) into the buffer. 
	====================*/
	
	/*======== void execute ( char *, char ** ) ==========
	Inputs:  char *file, char **argv
	Returns: none

	====================*/
	```
