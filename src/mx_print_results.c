#include "../inc/pathfinder.h"

void mx_print_ways(int countsIsalnds, char **cities, int **matrix, int **matrix_solution, int countsCities) {
    int *way = malloc((countsCities) * sizeof(int));
    for (int i = 0; i < countsIsalnds; i++) {
        for (int j = i + 1; j < countsIsalnds; j++) {
            way[0] = j;
            way[1] = i;
            int moves = 1;
            mx_print_each_way(cities, matrix, matrix_solution, countsIsalnds, moves, way);
        }
    }
    free(way);
}

void mx_print_each_way(char **cities, int **matrix, int **matrix_solution, int countsIsalnds, int moves, int *way) {
    int departure = way[0];
    int destination = way[moves];
    for (int i = 0; i < countsIsalnds; i++) {
        int check = matrix_solution[destination][departure] - matrix_solution[i][departure];
        if((matrix[destination][i] == check) && i != way[moves]) {
            way[moves + 1] = i;
            mx_print_each_way(cities, matrix, matrix_solution, countsIsalnds, moves + 1, way);
        }
    }
    if (way[moves] != departure) return;
    mx_print_main_words(cities, matrix_solution, way, moves, matrix);
}

void mx_print_main_words(char **cities, int **matrix_solution, int *way, int moves, int **matrix) {
    mx_printstr("========================================");
    mx_printchar('\n');
    mx_printstr("Path: ");
    mx_printstr(cities[way[1]]);
    mx_printstr(" -> ");
    mx_printstr(cities[way[0]]);
    mx_printchar('\n');
    mx_printstr("Route: ");
    mx_print_extra(moves, way, cities);
    mx_printchar('\n');
    mx_printstr("Distance: ");
    mx_print_dist(moves, way, matrix, matrix_solution);
    mx_printchar('\n');
    mx_printstr("========================================");
    mx_printchar('\n');
}

void mx_print_extra(int moves, int *way, char **cities) {
    if (moves > 2) {
        for (int i = 1; i < moves + 1; i++) {
            mx_printstr(cities[way[i]]);
            if (i < moves)
                mx_printstr(" -> ");
        }
    }
    else {
        mx_printstr(cities[way[1]]);
        mx_printstr(" -> ");
        mx_printstr(cities[way[0]]);
    }
}

void mx_print_dist(int moves, int *way, int **matrix, int **matrix_solution) {
    if (moves > 2) {
       for (int i = 1; i < moves; i++) {
            int temp = matrix[way[i]][way[i + 1]];
            mx_printint(temp);
            if (i < moves - 1) mx_printstr(" + ");
        }
        mx_printstr(" = ");
        mx_printint(matrix_solution[way[0]][way[1]]);
    }
    else mx_printint(matrix_solution[way[0]][way[1]]);
}

