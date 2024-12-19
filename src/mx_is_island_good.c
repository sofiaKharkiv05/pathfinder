#include "pathfinder.h"


void mx_is_island_good(char *islands, int line) {
    int end_one = mx_get_char_index(islands, '-') - 1;

    if (end_one < 0) {
        mx_print_err_line(line);
    }

    for (int i = 0; i <= end_one; i++) {
        if (!mx_is_letter(islands[i])) {
            mx_print_err_line(line);
        }
    }

    int start_two = end_one + 1;
    int end_two = mx_get_char_index(islands, ',') - 1;
    
    if (end_two <= start_two || end_two >= mx_strlen(islands)) {
        mx_print_err_line(line);
    }

    for (int i = start_two + 1; i <= end_two; i++) {
        if (!mx_is_letter(islands[i])) {
            mx_print_err_line(line);
        }
    }

    char first_part[end_one + 2]; 
    char second_part[end_two - start_two + 1];

    mx_strncpy(first_part, islands, end_one + 1);
    first_part[end_one + 1] = '\0';

    mx_strncpy(second_part, islands + start_two + 1, end_two - start_two);
    second_part[end_two - start_two] = '\0'; 

    if (mx_strcmp(first_part, second_part) == 0) {
        mx_print_err_line(line);
    }
}


