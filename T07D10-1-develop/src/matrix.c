#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int input(int **array, int n, int m);
void output(int **array, int n, int m);
int length(int *n, int *m);
int input_for_static_array(int array[SIZE][SIZE], int *n, int *m);
void output__for_static_array(int array[SIZE][SIZE], int n, int m);
int **array_of_pointers_to_array(int **array, int n, int m);
int **array_of_pointers_to_segments(int **array, int *arr, int n, int m);
int **array_of_p_to_arr_seg_within_one_buffer(int **array, int n, int m);

int main() {
    char choice;
    if (scanf("%c", &choice) != 1) {
        printf("n/a");
    } else {
        switch (choice) {
            case '1':
                int array[SIZE][SIZE] = {0}, n, m;
                if (input_for_static_array(array, &n, &m) == 0) {
                    printf("n/a");
                } else {
                    output__for_static_array(array, n, m);
                }
                break;
            case '2':
                int **arr1 = NULL;
                int n1, m1;
                if (length(&n1, &m1) == 0) {
                    printf("n/a");
                } else {
                    arr1 = array_of_pointers_to_array(arr1, n1, m1);
                    if (arr1 == NULL) {
                        printf("n/a");
                    } else {
                        if (input(arr1, n1, m1) == 0) {
                            printf("n/a");
                            for (int i = 0; i < n1; ++i) {
                                free(arr1[i]);
                            }
                            free(arr1);
                        } else {
                            output(arr1, n1, m1);
                            for (int i = 0; i < n1; ++i) {
                                free(arr1[i]);
                            }
                            free(arr1);
                        }
                    }
                }
                break;
            case '3':
                int **p_arr = NULL;
                int *v_arr = NULL;
                int n2, m2;
                if (length(&n2, &m2) == 0) {
                    printf("n/a");
                } else {
                    p_arr = malloc(n2 * sizeof(int *));
                    v_arr = malloc(n2 * m2 * sizeof(int));
                    array_of_pointers_to_segments(p_arr, v_arr, n2, m2);
                    if (p_arr == NULL) {
                        printf("n/a");
                    } else {
                        if (input(p_arr, n2, m2) == 0) {
                            printf("n/a");
                        } else {
                            output(p_arr, n2, m2);
                        }
                    }
                    free(v_arr);
                    free(p_arr);
                }
                break;
            case '4':
                int n3, m3;
                int **arr2 = NULL;
                if (length(&n3, &m3) == 0) {
                    printf("n/a");
                } else {
                    arr2 = array_of_p_to_arr_seg_within_one_buffer(arr2, n3, m3);
                    if (arr2 == NULL) {
                        printf("n/a");
                    } else {
                        if (input(arr2, n3, m3) == 0) {
                            printf("n/a");
                            free(arr2);
                        } else {
                            output(arr2, n3, m3);
                            free(arr2);
                        }
                    }
                }
                break;
            default:
                printf("n/a");
                break;
        }
    }
}

int input_for_static_array(int array[SIZE][SIZE], int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n > SIZE || *m > SIZE || *n <= 0 || *m <= 0) {
        return 0;
    }
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            scanf("%d", &array[i][j]);
        }
    }
    return 1;
}

int input(int **array, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (scanf("%d", &array[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

void output__for_static_array(int array[SIZE][SIZE], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m - 1) {
                printf("%d ", array[i][j]);
            } else {
                printf("%d", array[i][j]);
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

void output(int **array, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m - 1) {
                printf("%d ", array[i][j]);
            } else {
                printf("%d", array[i][j]);
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

int **array_of_pointers_to_array(int **array, int n, int m) {
    array = malloc(n * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        array[i] = malloc(m * sizeof(int));
        if (array[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(array[j]);
            }
            free(array);
        }
    }
    return array;
}

int **array_of_pointers_to_segments(int **array, int *arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        array[i] = arr + m * i;
    }
    return array;
}

int **array_of_p_to_arr_seg_within_one_buffer(int **array, int n, int m) {
    array = malloc(n * m * sizeof(int) + n * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }
    int *ptr = (int *)(array + n);
    for (int i = 0; i < n; ++i) {
        array[i] = ptr + m * i;
    }
    return array;
}

int length(int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n > SIZE || *m > SIZE || *n <= 0 || *m <= 0) {
        return 0;
    }
    return 1;
}