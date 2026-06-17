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

//print string
void print_string(String str);

//return the char at index
char at(int i);

//empty the string
void clear();

//compares string equality
bool isEqual(String a, String b);







#endif