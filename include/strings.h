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
void string_print(const String* str);

//print string
void string_println(const String* str);

//return the char at index
char string_at(const String* str, int i);

//append one String to another String
void string_append(String* str, const String* str_too);

//append a c style string to a String
void string_append_c(String* str, const char* lit);

//extracts a string from a String given range
String string_substr(const String* str, int start, int end);

//inserts a String into another String
void string_insert(String* str, int ndx, const String* str_too);

//inserts char* into a String
void string_insert_c(String* str, int ndx, const char* c);

//finds a substring String in String, return index of first instance, returns -1 if not found
int string_find(String* str, String* str_too);

//finds a substring char* in String, return index of first instance, returns -1 if not found
int string_find_c(String* str, char* c);

//replaces a portion of String at range
void string_replace_c(String* str, int ndx, char* line);

//replaces a portion of a String with String
void string_replace(String* str, int ndx, String* str_too);

//frees the String from memory
void string_free(String* str);

//empty the string
void clear();

//removes plain whitespaces at end and start of strings
void string_trim(String* str);

#endif