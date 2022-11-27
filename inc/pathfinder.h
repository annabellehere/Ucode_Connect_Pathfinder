#pragma once

#include "../libmx/inc/libmx.h"

//checks
void mx_check_validate(char *file, char *argv[]);
void mx_check_lines(char **lines, int lines_count, char *file);
int mx_check_alpha(char **lines, int numOfLine, int indOfChar);
void mx_check_counts(int chars_per_word, int temp_chars, int line, char *file, char **lines);
void mx_check_duplicates(char **lines, char **cities);
void mx_check_argv(int argc, char *argv[]);
void mx_checkCities(char **cities, int countsCities, char **lines);
void mx_check_cities(char **cities, char **lines);

// matrix
char **mx_eachCity(char **temp, int countsCities);
char **mx_allCities(char *file);
char **mx_liteToComponents(char *line);
int **mx_makeMatrix(char **file_lines, char **vertex_arr, int size);
int **mx_solution(int **matrix, int countsCities);

// utili
int mx_count_lines (char **cities);
void mx_del_int(int **matrix, int countsCities);
void mx_invalid_number(char **temp, char **cities, char **lines);
int mx_index(char **strarr, char *str);

//prints
void mx_print_ways(int countsIsalnds, char **cities, int **matrix, int **matrix_solution, int countsCities);
void mx_print_each_way(char **cities, int **matrix, int **matrix_solution, int countsIsalnds, int moves, int *way);
void mx_print_main_words(char **cities, int **matrix_solution, int *way, int moves, int **matrix);
void mx_print_extra(int moves, int *way, char **cities);
void mx_print_dist(int moves, int *way, int **matrix, int **matrix_solution);
void mx_printerr_line(int line);



