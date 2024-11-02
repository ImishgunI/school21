#include <stdio.h>
#include <stdlib.h>

int input(int *array, int n);
void output(int *array, int n);
void sort(int *array, int n);
int length(int *n);

int main() {
    int n;
    length(&n);
    int *array = calloc(n, sizeof(int));
    if (input(array, n) == 0) {
        printf("n/a");
    } else {
        sort(array, n);
        output(array, n);
    }
    free(array);
}

int input(int *array, int n) {
    int k;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &k) != 1) {
            return 0;
        } else {
            array[i] = k;
        }
    }
    return 1;
}

void output(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%d ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }
}

void sort(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int length(int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        return 0;
    }
    return 1;
}