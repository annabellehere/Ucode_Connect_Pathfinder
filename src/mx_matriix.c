#include "../inc/pathfinder.h"

int **mx_makeMatrix(char **lines, char **each_city, int size) {
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) matrix[i] = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = 9999999;
        }
    }
    for (int i = 1; lines[i]; i++) {
        char **one_line = mx_liteToComponents(lines[i]);
        if (mx_atoi(one_line[2]) >= 2147483647) {
            mx_del_strarr(&each_city);
            mx_del_strarr(&lines);
            mx_del_strarr(&one_line);
            for (int i = 0; i < size; i++) {
                free(matrix[i]);
            }
            free(matrix);
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);
        }
        matrix[mx_index(each_city, one_line[0])][mx_index(each_city, one_line[1])] = mx_atoi(one_line[2]);
        matrix[mx_index(each_city, one_line[1])][mx_index(each_city, one_line[0])] = mx_atoi(one_line[2]);
        mx_del_strarr(&one_line);
    }
    return matrix;
}


char **mx_liteToComponents(char *line) {
    char **strarr = malloc(4 * sizeof(char *));
    for (int i = 0; i < 4 ; i++) strarr[i] = NULL;
    strarr[0] = mx_strndup(line, mx_get_char_index(line, '-'));
    line += mx_strlen(strarr[0]) + 1;
    strarr[1] = mx_strndup(line, mx_get_char_index(line, ','));
    line += mx_strlen(strarr[1]) + 1;
    strarr[2] = mx_strndup(line, mx_get_char_index(line, '\n'));
    return strarr;
}

int mx_index(char **str1, char *str2) {
    int result = 0;
    while (str1[result] != NULL) {
        if (mx_strcmp(str1[result], str2) != 0) {
            result++;
            continue;
        }
        else return result;
    }
    return -1;
}



