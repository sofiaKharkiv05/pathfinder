#include "pathfinder.h"


void mx_is_first_line_valid(char* one_line) {

     if (!one_line) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    int size = mx_strlen(one_line);

    if (size == 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    if (size < 1 || size > 10) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    if (one_line[0] == '0') {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    for (int i = 0; i < size; i++) {
        if (!mx_isdigit(one_line[i])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }

    int res = mx_atoi(one_line);

    if (res > 2147483647){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    
}


