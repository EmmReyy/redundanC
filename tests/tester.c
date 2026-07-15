#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World!");
    String str_too = new_string("Howdy");

    string_replace(&str, 0, &str_too);
        
    string_println(&str);
}

