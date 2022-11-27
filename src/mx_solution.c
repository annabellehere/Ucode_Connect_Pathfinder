#include "../inc/pathfinder.h"

int **mx_solution(int **matrix, int countsCities) {
    int **matrix_solution = malloc(countsCities * countsCities * sizeof(int *) + 1);
    for (int i = 0; i < countsCities; i++) matrix_solution[i] = malloc(countsCities * sizeof(int));
    for (int i = 0; i < countsCities; i++) {
        for (int j = 0; j < countsCities; j++) matrix_solution[i][j] = matrix[i][j];
    }
    for(int k = 0 ; k < countsCities; k++) {
        for(int i = 0 ; i < countsCities; i++) {
            for(int j = 0 ; j < countsCities; j++) {
                if (matrix_solution[i][k] + matrix_solution[k][j] < matrix_solution[i][j] && i != j)
                    matrix_solution[i][j] = matrix_solution[i][k] + matrix_solution[k][j];
            }
        }
    }
    for (int i = 0; i < countsCities; i++) {
        for (int j = 0; j < countsCities; j++) {
            if (matrix_solution[i][j] == 9999999) matrix_solution[i][j] = 0;
        }
    }
    return matrix_solution;
}

void mx_del_int(int **matrix, int countsCities) {
    for (int i = 0; i < countsCities; i++) free(matrix[i]);
    free(matrix);
}



