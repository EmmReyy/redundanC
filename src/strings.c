#include "strings.h"
#include <string.h>
#include <stdio.h>


void secret_string_append(String* str, const char* c){
    
    int app_len = strlen(c);
    int new_allocate =  str->allocated+app_len;

    if (str->allocated < str->length + 1 + app_len){
        char* safety = realloc(str->val, new_allocate);

        if (safety == NULL) {
            fprintf(stderr, "Failed to grow memory block!\n");
        }
        str->val = safety;
        str->allocated = new_allocate;
    }

    //memcpy(str->val+str->length, c, app_len);
    strcat(str->val, c);
}







String new_string(char *c) {

    String this;

    if (c == NULL){
        fprintf(stderr, "Dumbass Error: String value is empty.\n");  
        return this; 
    }

    this.length = strlen(c);
    this.allocated = this.length + 1;
    this.val = malloc(this.allocated);

    if (this.val == NULL) {
        fprintf(stderr, "Fatal Error: Memory allocation failed in new_string.\n");  
        this.length = 0;
        this.allocated = 0;
        return this; 
    }

    memcpy(this.val, c, this.allocated);

    return this;
}

void change_string(String* str, const char* c){
    if (str == NULL || c == NULL){
        fprintf(stderr, "Dumbass Error: String value is empty.\n");  
    }

    str->length = strlen(c);
    str->allocated = str->length + 1;

    free(str->val);

    str->val = malloc(str->allocated);
    if (str->val != NULL) {
        memcpy(str->val, c, str->allocated);
    }
}

void print_string(const String* str){
    printf("%s", str->val);
}


char string_at(const String* str, int i){
    return *(str->val + i);
}

void string_append(String* str, const String* str_too){

    secret_string_append(str, str_too->val);
}

void string_append_c(String* str, const char* lit){

    secret_string_append(str, lit);
}

