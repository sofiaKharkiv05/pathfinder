#include "pathfinder.h"

// Функція для звільнення пам'яті
void freeIslands(Islands* islands) {
    for (int i = 0; i < islands->count; i++) {
        free(islands->Islands[i]);
    }
    free(islands->Islands);
}

