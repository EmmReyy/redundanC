#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World!");
    string_println(&str);

    String sub = string_substr(&str, 1, 3);

    string_println(&sub);
        
}

