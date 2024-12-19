#include "pathfinder.h"

Path *createPath(int initialCapacity, int start, int end) {
    Path *newPath = (Path *)malloc(sizeof(Path));
    if (!newPath) return NULL;

    newPath->paths = (int **)malloc(initialCapacity * sizeof(int *));
    if (!newPath->paths) {
        free(newPath);
        return NULL;
    }

    newPath->pathCount = 0;
    newPath->capacity = initialCapacity;
    newPath->startIndex = start; 
    newPath->endIndex = end;     
    newPath->sum = (int *)malloc(initialCapacity * sizeof(int));
    newPath->size = (int *)malloc(initialCapacity * sizeof(int)); 
  
    return newPath;
}

void freePaths(Path *pathStruct) {
    if (pathStruct) {
        if (pathStruct->paths) {
            for (int i = 0; i < pathStruct->pathCount; i++) {
                free(pathStruct->paths[i]); 
            }
            free(pathStruct->paths);
        }
        free(pathStruct->sum); 
        free(pathStruct->size); 
        free(pathStruct); 
    }
}

Norm_Path* create_norm_path(int startIndex, int endIndex, int routeCount) {
    Norm_Path *newPath = (Norm_Path *)malloc(sizeof(Norm_Path));
    if (!newPath) {
        return NULL; 
    }

    newPath->startIndex = startIndex;
    newPath->endIndex = endIndex;
    newPath->route = (int **)malloc(routeCount * sizeof(int *));
    if (!newPath->route) {
        free(newPath); 
        return NULL;
    }

     for (int i = 0; i < routeCount; i++) {
        newPath->route[i] = NULL; 
     }

    newPath->sum = 0;

    return newPath;
}

void free_norm_path(Norm_Path *path) {
    if (path) {
        if (path->route) {
            for (int i = 0; path->route[i] != NULL; i++) {
                free(path->route[i]);
            }
            free(path->route); 
        }
        free(path); 
    }
}

void printNormPath(Norm_Path *n_path, int n, Islands islands, Bridges bridges[], int count_of_bridges) {
    for (int r = 0; r < n; r++) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(islands.Islands[n_path->startIndex]);
        mx_printstr(" -> ");
        mx_printstr(islands.Islands[n_path->endIndex]);
        mx_printstr("\n");

        if (n_path->route[r]) {
            long total_distance = 0;
            int count = 0;

            for (int i = 0; n_path->route[r][i] != -1; i++) {
                count++;
            }

            mx_printstr("Route: ");
            for (int i = 0; n_path->route[r][i] != -1; i++) {
                mx_printstr(islands.Islands[n_path->route[r][i]]);
                if (n_path->route[r][i + 1] != -1) {
                    mx_printstr(" -> ");
                }
            }
            mx_printstr("\n");

            mx_printstr("Distance: ");
            if (count == 2) {
                char* num = mx_itoa(n_path->sum);
                mx_printstr(num);
                free(num);
            } else {
                int first = 1; 
                for (int i = 0; n_path->route[r][i] != -1 && n_path->route[r][i + 1] != -1; i++) {
                    int current_island = n_path->route[r][i];
                    int next_island = n_path->route[r][i + 1];

                    for (int j = 0; j < count_of_bridges; j++) {
                        if ((bridges[j].indexIsland1 == current_island && bridges[j].indexIsland2 == next_island) ||
                            (bridges[j].indexIsland1 == next_island && bridges[j].indexIsland2 == current_island)) {
                            total_distance += bridges[j].size;
                            if (!first) {
                                mx_printstr(" + ");
                            }
                            char* num = mx_itoa(bridges[j].size);
                            mx_printstr(num);
                            free(num);
                            first = 0;
                            break; 
                        }
                    }
                }
                mx_printstr(" = ");
                mx_printstr(mx_itoa(total_distance));
            }
            mx_printstr("\n");
        }
        mx_printstr("========================================\n");
    }
}



int calculatePathSum(int **graph, int *path, int pathLength) {
    int sum = 0;
    for (int i = 0; i < pathLength - 1; i++) {
        sum += graph[path[i]][path[i + 1]]; 
    }
    return sum;
}

void resizePaths(Path *allPaths) {
    int newCapacity = allPaths->capacity * 2;
    allPaths->paths = (int **)mx_realloc(allPaths->paths, newCapacity * sizeof(int *));
    allPaths->sum = (int *)mx_realloc(allPaths->sum, newCapacity * sizeof(int));
    allPaths->size = (int *)mx_realloc(allPaths->size, newCapacity * sizeof(int));
    allPaths->capacity = newCapacity;
}

void findAllPathsUtil(int **graph, int start, int end, bool *visited, int *path, int pathIndex, int size, Path *allPaths) {
    visited[start] = true; 
    path[pathIndex] = start; 
    pathIndex++;

    if (start == end) {
        if (allPaths->pathCount >= allPaths->capacity) {
            resizePaths(allPaths);
        }
        
        allPaths->paths[allPaths->pathCount] = (int *)malloc((pathIndex + 1) * sizeof(int));
        if (!allPaths->paths[allPaths->pathCount]) {
            return;
        }

        for (int i = 0; i < pathIndex; i++) {
            allPaths->paths[allPaths->pathCount][i] = path[i];
        }
        allPaths->paths[allPaths->pathCount][pathIndex] = -1;

        allPaths->sum[allPaths->pathCount] = calculatePathSum(graph, path, pathIndex);
        allPaths->size[allPaths->pathCount] = pathIndex; 

        allPaths->pathCount++; 
    } else {
        for (int i = 0; i < size; i++) {
            if (graph[start][i] != INT_MAX && !visited[i]) {
                findAllPathsUtil(graph, i, end, visited, path, pathIndex, size, allPaths);
            }
        }
    }

    pathIndex--;
    visited[start] = false; 
}



void mx_copy_path(Path *path, Norm_Path *n_path, int minSum, int n, Islands islands, Bridges bridges[], int count_of_bridges) {
   
    n_path->startIndex = path->startIndex;
    n_path->endIndex = path->endIndex;
    n_path->sum = minSum;

    n_path->route = (int **)malloc((n + 1) * sizeof(int *));

    int counter = 0;
    for (int i = 0; i < path->pathCount && counter < n; i++) {
        if (path->sum[i] == minSum) {;

            n_path->route[counter] = (int *)malloc((path->size[i] + 1) * sizeof(int)); 

            for (int j = 0; j < path->size[i]; j++) {
                n_path->route[counter][j] = path->paths[i][j];
            }
            n_path->route[counter][path->size[i]] = -1; 

            counter++;
        }
    }

    n_path->route[counter] = NULL; 

    printNormPath(n_path, n, islands, bridges, count_of_bridges);
}



void mx_find_shortest_paths(Path *allPath, Islands islands, Bridges bridges[], int count_of_bridges) {
    int count = 0;
    int start = allPath->startIndex;
    int end = allPath->endIndex;

    int min = allPath->sum[0];
 for (int i = 1; i < allPath->pathCount; i++) {
        if (min > allPath->sum[i]) {
            min = allPath->sum[i];
        }
    }   

    for (int i = 0; i < allPath->pathCount; i++) {
        if (min == allPath->sum[i]) {
            count++;
        }
    } 


    Norm_Path *n_path = create_norm_path(start, end, count);
    mx_copy_path(allPath, n_path, min, count, islands, bridges, count_of_bridges);
    free_norm_path(n_path);
}



void findAllPaths(int **graph, int start, int end, int size, Islands islands, Bridges bridges[], int count_of_bridges) {
    bool *visited = (bool *)malloc(size * sizeof(bool)); 
    int *path = (int *)malloc(size * sizeof(int)); 
    Path *allPaths = createPath(10, start, end); 

    for (int i = 0; i < size; i++) {
        visited[i] = false; 
    }

    findAllPathsUtil(graph, start, end, visited, path, 0, size, allPaths);

    mx_find_shortest_paths(allPaths, islands, bridges, count_of_bridges);

    freePaths(allPaths); 
    free(visited); 
    free(path); 
   
}

