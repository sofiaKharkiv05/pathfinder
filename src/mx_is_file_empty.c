#include "pathfinder.h"

char* mx_is_file_empty(const char* filename){
    char* res = mx_file_to_str(filename);
    if (!res || mx_strlen(res) == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(0);
    }
    return res;
}


