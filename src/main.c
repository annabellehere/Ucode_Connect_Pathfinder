#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    mx_check_argv(argc, argv);
    char *file = mx_file_to_str(argv[1]);
    mx_check_validate(file, argv);
    char **lines = mx_strsplit(file, '\n');
    int countsCities = mx_atoi(lines[0]);
    char **cities = mx_allCities(file);
    mx_strdel(&file);
    mx_check_cities(cities, lines);
    char **each_city = mx_eachCity(cities, countsCities);
    mx_del_strarr(&cities);
    mx_checkCities(each_city, countsCities, lines);
    mx_check_duplicates(lines, each_city);
    int **matrix = mx_makeMatrix(lines, each_city, countsCities);
    mx_del_strarr(&lines);
    int **matrix_solution = mx_solution(matrix, countsCities);
    mx_print_ways(countsCities, each_city, matrix, matrix_solution, countsCities);
    mx_del_strarr(&each_city);
    mx_del_int(matrix_solution, countsCities);
    mx_del_int(matrix, countsCities);
}






