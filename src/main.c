#include "pathfinder.h"

int main(int argc, char const *argv[]){
  mx_bad_count_argv(argc);
  const char* file = argv[1];
  mx_is_file_exit(file);

  char* str = mx_is_file_empty(file);
  char** splitStr = mx_strsplit(str, '\n');
   mx_is_first_line_valid(splitStr[0]);
 
    mx_is_format_good(splitStr);
   
   int countofLine = 0;
    while (splitStr[countofLine] != NULL){
        countofLine++;
    }
    int count_worlds = mx_count_substr(str, "\n");

    if (countofLine != count_worlds){
        mx_print_err_line(countofLine+1);
    }
       
    mx_is_invalid_count_of_islands(splitStr, mx_atoi(splitStr[0]), countofLine);
    
    free(str); 

    for (int i = 0; splitStr[i] != NULL; i++) {
        free(splitStr[i]);  
    }
    free(splitStr);  

    return 0;
}


