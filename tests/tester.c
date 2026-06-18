#include <stdio.h>
#include "strings.h"

int main(){

    String str = new_string("Hello World!");

    print_string(&str);

    int ndx = 0;
    printf("\n%c is at %i!", string_at(&str, ndx), ndx);
    printf("\ndone");
}

