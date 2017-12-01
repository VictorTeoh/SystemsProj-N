# SystemsProj-N

uhh  
Features:  
	Forks and executes commands!  
	Parses multiple commands separated by semicolons  
	Redirects using >, <  
	

Attempted:  
	 
Bugs:  
	
        
	
Files & Function Headers:  
shell.c  
        void print_prompt()  
        Prints the prompt after each command.  
        The prompt features the user name (!!!), hostname, the cwd, and time in color  
util.c  
        void strstrip(char *)  
        input : A string  
        
        void parse_args( char **, char * );  
        
        void parse_commands( char **, char * );  
        input : char **commands   
        char *line  
        Works on the given line to accomodate for mutiple commands in a single line  
        
        int execute( char *, char ** );   
          
        void getctime( char *, size_t )  
        input : char *buffer  
        size_t size  
        Puts the current time (hr:min:sec) in to the buffer.  
