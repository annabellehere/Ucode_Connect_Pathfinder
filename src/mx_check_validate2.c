#include "../inc/pathfinder.h"

void mx_check_duplicates(char **lines, char **cities) {
    int lines_count = 0;
    while (lines[lines_count]) lines_count++;
    char **temp = malloc((lines_count + 1) * sizeof(char *));
    for (int i = 0; i < lines_count; i++) {
        temp[i] = mx_strndup(lines[i], mx_get_char_index(lines[i], ','));
    }
    temp[lines_count] = NULL;
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (mx_strcmp(temp[i], temp[j]) == 0 && temp[j][0] != '\0' && j != i) {
                mx_del_strarr(&cities);
                mx_del_strarr(&lines);
                mx_del_strarr(&temp);
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
    mx_del_strarr(&temp);
}

void mx_check_argv(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    if (open(argv[1], O_RDONLY) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
}

void mx_check_cities(char **cities, char **lines) {
    int count_lines = mx_count_lines (cities);
    for (int i = 0; i < count_lines; i += 2) {
        if(mx_strcmp(cities[i], cities[i + 1]) == 0) {
            mx_del_strarr(&lines);
            mx_del_strarr(&cities);
            mx_printerr("error: line ");
            char *output = mx_itoa(i + 2);
            mx_printerr(output);
            mx_printerr(" is not valid\n");
            free(output);
            exit(0);
        }
    }
}

int mx_count_lines (char **cities) {
    int count_lines = 0;
    while (cities[count_lines]) count_lines++;
    return count_lines;
}



