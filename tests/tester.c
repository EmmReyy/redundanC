#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World!");
    String str_too = new_string(" Good to see you!");

    string_append(&str, &str_too);
    print_string(&str);

    change_string(&str, "\nGoodbye World!");
    string_append_c(&str, " See you soon!");
    print_string(&str);

    
    int ndx = 11;


    printf("\n%c is at %i!", string_at(&str, ndx), ndx);
    printf("\ndone");
}

