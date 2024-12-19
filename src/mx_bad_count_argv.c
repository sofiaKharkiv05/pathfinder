#include "pathfinder.h"

void mx_bad_count_argv(int argc){
    if (argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
}


