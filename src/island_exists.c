#include "pathfinder.h"

int cmp_str(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

bool island_exists(char** arrIsland, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (cmp_str(arrIsland[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

