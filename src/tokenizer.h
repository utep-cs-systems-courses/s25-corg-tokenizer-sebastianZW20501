#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    if ((c == ' ' || c == '\t') && c != '\0') {
        return 1;
    }
    return 0;
};

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
       if (c != ' ' && c != '\t' && c != '\0') {
        return 1;
    }
    return 0;
};

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
       while (*s != '\0' && (*s == ' ' || *s == '\t')) {
        s++;
    }
    
    if (*s == '\0') {
        return NULL;
    }
    
    return s;
}; 

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){

   while (*token != '\0' && *token != ' ' && *token != '\t') {
        token++; 
    }
    
    while (*token != '\0' && (*token == ' ' || *token == '\t')) {
        token++; 
    }
    
    return token;
};

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
   
    int count = 0; 
    
    while (*s != '\0' && (*s == ' ' || *s == '\t')) {
        s++;
    }

    while (*s != '\0') {
       
        if (*s != ' ' && *s != '\t') {
            count++;

            while (*s != '\0' && *s != ' ' && *s != '\t') {
                s++;
            }
        }

        while (*s != '\0' && (*s == ' ' || *s == '\t')) {
            s++;
        }
    }

    return count;
};

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
   
   char *copy = (char *)malloc(len + 1);  // len + 1 to accommodate the null terminator

    if (copy == NULL) {
        return NULL;  // If malloc fails, return NULL
    }

    for (short i = 0; i < len; i++) {
        copy[i] = inStr[i];
    }

    copy[len] = '\0';

    return copy;
};

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    int num_tokens = count_tokens(s);
    
    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
    
    if (tokens == NULL) {
        return NULL;
    }

    int i = 0;
    char *start = token_start(s); 

    while (start != NULL) {

        char *end = token_terminator(start);
        
        short len = end - start;
        
        tokens[i] = copy_str(start, len);
        
        if (tokens[i] == NULL) {
           
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
           
            free(tokens);
            return NULL;
        }
        
        start = token_start(end);
        
        i++;
       
   }

    tokens[i] = NULL;

    return tokens;
       
};

/* Prints all tokens. */
void print_tokens(char **tokens){
   
   if (tokens == NULL) {
        printf("No tokens to print.\n");
        return;
    }

    int i = 0;
   
    while (tokens[i] != NULL) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        i++;
    }
   
};

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
   
    if (tokens == NULL) return;

    int i = 0;
   
    while (tokens[i] != NULL) {
        free(tokens[i]); 
        i++;
    }
    
    free(tokens);
};

#endif
