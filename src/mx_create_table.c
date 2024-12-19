#include "pathfinder.h"

void mx_create_table(Bridges bridges[], int count_of_bridges, Islands islands) {
    int infinity = INT_MAX; 
    int size_of_table = islands.count;
    int** table = (int**)malloc(size_of_table * sizeof(int*));
    
for (int i = 0; i < size_of_table; i++) {
  
    table[i] = (int*)malloc(size_of_table * sizeof(int));
}
    int is_was_here[size_of_table][size_of_table];

    for (int i = 0; i < size_of_table;i++) {
        for (int j = 0; j < size_of_table; j++) {
            table[i][j] = infinity; 
            is_was_here[i][j]= 0 ;
        }
        table[i][i] = 0; 
    }

    for (int i = 0; i < count_of_bridges;i++) {
        int island1 = bridges[i].indexIsland1;
        int island2 = bridges[i].indexIsland2;
        int size = bridges[i].size;

        table[island1][island2] = size;
        table[island2][island1] = size;
    }

        for (int i = 0; i < size_of_table - 1; i++) {
        for (int j = i + 1; j < size_of_table; j++) {
            findAllPaths(table, i, j, size_of_table, islands, bridges, count_of_bridges);
        }
    } 

    for (int i = 0; i < size_of_table; i++) {
        free(table[i]); 
    }
free(table);   

}
