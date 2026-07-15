#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World");

    int ndx = string_find_c(&str, "orl");

    printf("%d\n",ndx);
        
    
}

