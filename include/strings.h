#ifndef REDUNDANC_STRINGS_H
#define REDUNDANC_STRINGS_H
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {

    char* val;
    size_t length;
    size_t allocated;

} String;

//string init
String new_string(char* c);

//for changing a string's value. more efficent
void change_string(String* str, const char* c);

//print string
void print_string(const String* str);

//return the char at index
char string_at(const String* str, int i);

void string_append(String* str, const String* str_too);

void string_append_c(String* str, const char* lit);

void string_insert(String* str, int ndx, const String* str_too);

void string_insert_c(String* str, int ndx, const char* c);

void string_replace(String* str, int start, int end, char* line);

void string_free(String* str);

//empty the string
void clear();








#endif