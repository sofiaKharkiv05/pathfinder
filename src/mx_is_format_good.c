#include "pathfinder.h"


void mx_is_format_good(char **islands) {
    for (int i = 1; islands[i] != NULL; i++) {
        int count = mx_count_words(islands[i], ',');
        if (count != 2) {
            mx_print_err_line(i + 1);
        }

        int index = mx_get_char_index(islands[i], ',') + 1;
        if (index <= 0 || islands[i][index] == '\0') {
            mx_print_err_line(i + 1);
        }

        while (islands[i][index] != '\0') {
            if (!mx_isdigit(islands[i][index])) {
                mx_print_err_line(i + 1);
            }
            index++;
        }

        mx_is_island_good(islands[i], i + 1);
    }
}



