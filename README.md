# SystemsProj-N


Function Headers:  
void strstrip(char *)
input : 


void parse_args( char **, char * )  
void parse_commands( char **commands, char *line )  
input : char **commands  
        char *line  
        Works on the given line to accomodate for mutiple commands in a single line
int execute( char *, char ** )  
void getctime( char *, size_t )  
input : char *buffer  
        size_t size  
Puts the current time (hr:min:sec) in to the buffer.
