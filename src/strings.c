#include "strings.h"
#include <string.h>
#include <stdio.h>


String new_string(char *c) {
    String this;

    this.length = strlen(c);
    this.allocated = this.length + 1;

    this.val = malloc(this.allocated);

    strcpy(this.val, c);

    return this;
}


void print_string(String* str){
    printf("%s", str->val);
}


char string_at(String* str, int i){
    return *(str->val + i);
}

