#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <unistd.h>
#include <wchar.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_Islands{
    char** Islands;
    int count;
}Islands;

typedef struct s_Bridges{
    int indexIsland1;
    int indexIsland2;
    long size;
}Bridges;

typedef struct s_paths {
    int **paths;      
    int pathCount;    
    int capacity;
    int startIndex;
    int endIndex;
    int *sum;
    int *size;    
} Path;

 typedef struct s_path_root{
    int startIndex;
    int endIndex;
    int **route;
    int sum;
 } Norm_Path;

Islands createIslands(int count);
void freeIslands(Islands* islands);
void mx_printerr(const char *s);
void mx_bad_count_argv(int argc);
void mx_is_file_exit(const char* filename);
char* mx_is_file_empty(const char* filename);
void mx_is_first_line_valid(char* one_line);
void mx_print_err_line(int count);
void mx_is_island_good(char *islands, int line);
void mx_is_format_good(char **islands);
void mx_is_dup_or_big(Bridges bridges[], int count);
bool island_exists(char** arrIsland, int count, const char *name);
void mx_is_invalid_count_of_islands(char** split, int count, int lines);
void mx_create_table(Bridges bridges[], int count_of_bridges, Islands islands);
void findAllPaths(int **graph, int start, int end, int size, Islands islands, Bridges bridges[], int count_of_bridges);
void findAllPathsUtil(int **graph, int start, int end, bool *visited, int *path, int pathIndex, int size, Path *allPaths);
int calculatePathSum(int **graph, int *path, int pathLength);
void printNormPath(Norm_Path *n_path, int n, Islands islands, Bridges bridges[], int count_of_bridges);
void free_norm_path(Norm_Path *path);
Norm_Path* create_norm_path(int startIndex, int endIndex, int routeCount);
void freePaths(Path *pathStruct);
Path *createPath(int initialCapacity, int start, int end);
#endif
