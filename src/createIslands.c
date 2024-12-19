#include "pathfinder.h"

/// Функція для ініціалізації структури
Islands createIslands(int count) {
    Islands islands;
    islands.count = count;
    islands.Islands = (char**)malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
        islands.Islands[i] = (char*)malloc(100 * sizeof(char));
    }
    return islands;
}

