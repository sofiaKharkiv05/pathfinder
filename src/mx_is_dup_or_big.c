#include "pathfinder.h"

void mx_is_dup_or_big(Bridges bridges[], int count) {
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) { 
            if (bridges[i].indexIsland1 == bridges[j].indexIsland1 && 
                bridges[i].indexIsland2 == bridges[j].indexIsland2) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }

     long total_size = 0;
    for (int i = 0; i < count; i++) { 
        if (bridges[i].size > 2147483647 || bridges[i].size <= 0) { 
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);
        }    
        total_size += bridges[i].size;
        if (total_size > 2147483647 || total_size <= 0) { 
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);
        }
    }
}


