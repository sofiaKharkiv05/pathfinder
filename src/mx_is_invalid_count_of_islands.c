#include "pathfinder.h"

void mx_copy_island(Islands *islands_copied, Islands *islands_norm) {
    islands_norm->Islands = malloc(islands_norm->count * sizeof(char*));

    for (int i = 0; i < islands_norm->count; i++) {
        if (islands_copied->Islands[i] != NULL) {
            islands_norm->Islands[i] = mx_strdup(islands_copied->Islands[i]);
        } else {
            islands_norm->Islands[i] = NULL; 
        }
    }
}

void mx_is_invalid_count_of_islands(char** split, int count, int lines) {
    Islands islands = createIslands(count * 2);
    int actual_count = 0;
    Bridges bridges[lines];
    int count_bridges = 0;

    for (int i = 1; split[i] != NULL; i++) {
        int end_one = mx_get_char_index(split[i], '-') - 1;
        int start_two = end_one + 1;
        int end_two = mx_get_char_index(split[i], ',') - 1;

        char first_part[end_one + 2];
        char second_part[end_two - start_two + 1];

        mx_strncpy(first_part, split[i], end_one + 1);
        first_part[end_one + 1] = '\0';

        mx_strncpy(second_part, split[i] + start_two + 1, end_two - start_two);
        second_part[end_two - start_two] = '\0';

        if (!island_exists(islands.Islands, actual_count, first_part)) {
            mx_strcpy(islands.Islands[actual_count], first_part);
            actual_count++;
        }

        if (!island_exists(islands.Islands, actual_count, second_part)) {
            mx_strcpy(islands.Islands[actual_count], second_part);
            actual_count++;
        }

        if (count_bridges < lines) {
            bridges[count_bridges].indexIsland1 = -1;
            bridges[count_bridges].indexIsland2 = -1;

            for (int j = 0; j < actual_count; j++) {
                if (mx_strcmp(islands.Islands[j], first_part) == 0) {
                    bridges[count_bridges].indexIsland1 = j;
                }
                if (mx_strcmp(islands.Islands[j], second_part) == 0) {
                    bridges[count_bridges].indexIsland2 = j;
                }
            }
            int index = mx_get_char_index(split[i], ',') + 1;

        int iter = mx_strlen(split[i]- end_two);
        char size[iter]; 
        int size_index = 0;

    while (split[i][index] != '\0' && split[i][index] != '\n' && split[i][index] != '\r') {
        size[size_index] = split[i][index];
        size_index++;
        index++;
    }

        size[size_index] = '\0';
            bridges[count_bridges].size = mx_atoi(size);        
            count_bridges++;
        }
    }

    if (actual_count != count) {
        mx_printstr("error: invalid number of islands\n");
        exit(0);
    }

    Islands islands_norm = createIslands(actual_count);
	mx_copy_island(&islands, &islands_norm);
   freeIslands(&islands);
        mx_is_dup_or_big(bridges, count_bridges);
        mx_create_table(bridges, count_bridges, islands_norm);
        freeIslands(&islands_norm);
}




