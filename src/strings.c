#include "strings.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//internal functions

void secret_reallocer(String* str, int len){

        int new_allocate = len+1+str->allocated;

        if (str->allocated < str->length + 1 + len){
        char* safety = realloc(str->val, new_allocate);

        if (safety == NULL) {
            fprintf(stderr, "Failed to grow memory block!\n");
        }
        str->val = safety;
        str->allocated = new_allocate;
    }
}

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

    memcpy(str->val+str->length, c, app_len);
}

void secret_string_insert(String* str, int ndx, const char* c){

    int len = strlen(c);
    int new_allocate = str->allocated + len + 1;
    
    if (str->allocated < len+str->length +1){

        char* temp = realloc(str->val, new_allocate);
        if  (temp == NULL){
            fprintf(stderr, "Realloc failed.");
        }
        str->val = temp;
        str->allocated = new_allocate;
    }
    
    memcpy(str->val+ndx+len,  str->val+ndx,  len);
    memcpy(str->val+ndx, c, len);

}

int secret_string_find(String* str, char* c){

    int ndx = -1;

    for (int i = 0; i < str->length-1; i++){
        
        if (str->val[i] == c[0]){
            int j = 1+i;
            int k = 1;
            ndx = i;
            
            while(j < str->length-1){
                if (str->val[j] != c[k]){
                    ndx = -1;
                    j += str-> length;
                }
                j++;
                k++;
            }       
            if (ndx != -1){
                return ndx;
            }     
        }
    }

    if (ndx == -1){
        fprintf(stderr, "Couldn't find substring.\n");
    }
    return ndx;

}

void secret_string_replace(String* str, int ndx, char* line){
    int len = strlen(line);
    int new_alloc = str->allocated + len;

    secret_reallocer(str, len);

    memcpy(str->val, line, len);
}




String string_substr(const String* str, int start, int end){

    if (str->length < end){
        fprintf(stderr, "Ending range exceeded size of string");
        return new_string(NULL);
    }

    int len = 1+end-start;

    char* sub = malloc(len);
    memcpy(sub, str->val+start, len);
    sub[len] = '\0';
    String substr = new_string(sub);
    return substr;
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

void string_print(const String* str){
    printf("%s", str->val);
}

void string_println(const String* str){
    printf("%s\n", str->val);
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

void string_insert(String* str, int ndx, const String* str_too){
    secret_string_insert(str, ndx, str->val);
}

void string_insert_c(String* str, int ndx, const char* c){
    secret_string_insert(str, ndx, c);
}

int string_find_c(String* str, char* c){

    return secret_string_find(str, c);
}

int string_find(String* str, String* str_too){

    return secret_string_find(str, str_too->val);
}

void string_replace_c(String* str, int ndx, char* line){
    secret_string_replace(str, ndx, line);
}

void string_replace(String* str, int ndx, String* str_too){
    secret_string_replace(str, ndx, str_too -> val);
}

void string_trim(String* str){

    int start = -1;
    int end = -1;
    
    for (int i = 0; i < str->length -1; i++){
        if (!isspace(str->val[i])){
            start = i;
            break;
        }        
    }

    
    for (int j = str->length-1; j > 0; j--){
        if (!isspace(str->val[j])){
            end = j;    
            break;
        }
    }

    if (start != -1 && end != -1){
        
        for (int k = 0; k <= end; k++){
            str-> val[k] = str->val[start+k];
        }

        str->val[end-start+1] = '\0';
    }
}


