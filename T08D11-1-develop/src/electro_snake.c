#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/

void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void bubbleSort(int *arr, int n);

int main() {
    int **matrix, **result;
    int n, m;

    if (scanf("%d %d", &n, &m) != 2 || n == 0 || n == 0) {
        printf("n/a");
    } else {
        matrix = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) matrix[i] = malloc(m * sizeof(int));

        result = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) result[i] = malloc(m * sizeof(int));

        input(matrix, &n, &m);

        sort_horizontal(matrix, n, m, result);
        output(result, n, m);
        printf("\n\n");
        sort_vertical(matrix, n, m, result);
        output(result, n, m);

        for (int i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
        for (int i = 0; i < n; i++) free(result[i]);
        free(result);
    }

    return 0;
}

void input(int **matrix, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *sortedArray = calloc(n * m, sizeof(int));

    int index = 0;

    // копирование элементов в линейный массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sortedArray[index++] = matrix[i][j];
        }
    }

    // сортировка линейного массива
    bubbleSort(sortedArray, n * m);

    index = 0;
    for (int i = 0; i < m; i++) {
        if ((i + 1) % 2 != 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = sortedArray[index++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[i][j] = sortedArray[index++];
            }
        }
    }

    free(sortedArray);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *sortedArray = calloc(n * m, sizeof(int));

    int index = 0;

    // копирование элементов в линейный массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sortedArray[index++] = matrix[i][j];
        }
    }

    // сортировка линейного массива
    bubbleSort(sortedArray, n * m);

    index = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 != 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[j][i] = sortedArray[index++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[j][i] = sortedArray[index++];
            }
        }
    }

    free(sortedArray);
}

void bubbleSort(int *arr, int n) {
    int i = 0, j = n - 1, temp, p;
    p = arr[n / 2];

    do {
        while (*(arr + i) < p) i++;
        while (*(arr + j) > p) j--;
        if (i <= j) {
            temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) bubbleSort(arr + j, j + 1);
    if (n > i) bubbleSort(arr + i, n - i);
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) printf(" ");
        }
        if (i != n - 1) printf("\n");
    }
}