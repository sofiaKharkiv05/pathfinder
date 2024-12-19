#include "pathfinder.h"


void mx_is_file_exit(const char* filename){
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    close(fd);
}

