#ifndef REDUNDANC_STRINGS_H
#define REDUNDANC_STRINGS_H
#include <stddef.h>
#include <stdbool.h>

typedef struct {

    char* val;
    size_t length;

} String;

//string init
void string(char* c);

//add a char/line at the end
void append(char* c);

//return the char at index
char at(int i);

//empty the string
void clear();

//compares string equality
bool isEqual(String a, String b);







#endif