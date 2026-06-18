#include "strings.h"
#include <string.h>
#include <stdio.h>


String new_string(char *c) {

    String this;

    if (c == NULL){
        fprintf(stderr, "Dumbass Error: String value is empty.\n");  
        return; 
    }

    this.val = NULL;
    this.length = strlen(c);
    this.allocated = this.length + 1;

    this.val = realloc(this.val, this.allocated);

    if (this.val == NULL) {
        fprintf(stderr, "Fatal Error: Memory allocation failed in new_string.\n");  
        this.length = 0;
        this.allocated = 0;
        return this; 
    }

    memcpy(this.val, c, this.allocated);

    return this;
}


String change_string(String* str, char* c){
    if (str == NULL || c == NULL){
        fprintf(stderr, "Dumbass Error: String value is empty.\n");  
        return; 
    }

    str->length = strlen(c);
    str->allocated = str->length + 1;

    str->val = malloc(str->allocated);
    if (str->val != NULL) {
        memcpy(str->val, c, str->allocated);
    }
}

void print_string(String* str){
    printf("%s", str->val);
}


char string_at(String* str, int i){
    return *(str->val + i);
}

