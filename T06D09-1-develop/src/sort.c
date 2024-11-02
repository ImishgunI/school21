#include <stdio.h>

#define SIZE 10

int input(int *array, int n);
void output(int *array, int n);
void sort(int *array, int n);

int main() {
    int n = SIZE, array[SIZE];
    if (input(array, n) == 0) {
        printf("n/a");
    } else {
        sort(array, n);
        output(array, n);
    }
}

int input(int *array, int n) {
    int *p = array;
    for (; p - array < n; ++p) {
        scanf("%d", p);
    }
    char c;
    if ((c = getchar()) != '\n') {
        return 0;
    } else {
        return 1;
    }
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