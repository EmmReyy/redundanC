#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("    Hello World      ");
    string_trim(&str);
    string_print(&str);
    printf("!");
}

