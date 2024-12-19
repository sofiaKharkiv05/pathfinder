#include "pathfinder.h"


void mx_print_err_line(int count) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(count));
    mx_printerr(" is not valid\n");
    exit(0);
}



