#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World!");

    string_insert_c(&str, 6, "and goodbye ");
    string_println(&str);

  
        
}

