#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double ***matrix, int *n, int *m);  // Изменяем тип параметра matrix
void output(double det);

int main() {
    int n, m;
    double **matrix = NULL;  // Инициализация указателя
    input(&matrix, &n, &m);  // Передаем адрес указателя
    if (n != m) {
        printf("n/a");
        return 0;
    }
    double result = det(matrix, n, m);
    output(result);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void input(double ***matrix, int *n, int *m) {  // Изменяем тип параметра matrix
    scanf("%d %d", n, m);
    *matrix = malloc(*n * sizeof(double *));  // Используем *matrix для изменения указателя
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*m * sizeof(double));
        for (int j = 0; j < *m; j++) {
            scanf("%lf", &((*matrix)[i][j]));
        }
    }
}

void output(double det) { printf("%.6f", det); }

double det(double **matrix, int n, int m) {
    double determinant = 1;
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            int swap_found = 0;
            for (int j = i + 1; j < m; j++) {
                if (matrix[j][i] != 0) {
                    double *temp = matrix[i];
                    matrix[i] = matrix[j];
                    matrix[j] = temp;
                    determinant = -determinant;
                    swap_found = 1;
                    break;
                }
            }
            if (!swap_found) {
                return 0;
            }
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        determinant *= matrix[i][i];
    }
    return determinant;
}