#include "../inc/pathfinder.h"

char** mx_allCities(char *file) {
    char *str = mx_strdup(file);
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] != ' ' && !mx_isalpha(str[i])) str[i] = ' ';
    }
    char *str_no_spaces = mx_del_extra_spaces(str);
    char **cities = mx_strsplit(str_no_spaces, ' ');
    mx_strdel(&str);
    mx_strdel(&str_no_spaces);
    return cities;
}

void mx_checkCities(char **cities, int countsCities, char **lines) {
    int count = 0;
    for (int i = 0; cities[i]; i++) count++;
    if (count != countsCities) {
        mx_del_strarr(&cities);
        mx_del_strarr(&lines);
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
}

char **mx_eachCity(char **temp, int countsCities) {
    int index = 0;
    int lines_count = mx_count_lines(temp);
    char **cities = NULL;
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (mx_strcmp(temp[i], temp[j]) == 0 && j != i)
                temp[j][0] = '^';
        }
        cities = mx_realloc(cities, (index + 1) * sizeof(char *));
        if(mx_isalpha(temp[i][0])) {
            cities[index++] = mx_strdup(temp[i]);
        }
    }
    cities[countsCities] = NULL;
    return cities;
}


