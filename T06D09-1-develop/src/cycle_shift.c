#include <stdio.h>

#define SIZE 10

int input(int *a, int *n, int *shift);
void output(int *a, int n);
void cycle_shift(int *a, int n, int shift);

int main() {
    int n, a[SIZE], shift;
    if (input(a, &n, &shift) == 0) {
        printf("n/a");
    } else {
        cycle_shift(a, n, shift);
        output(a, n);
    }
}

int input(int *a, int *n, int *shift) {
    scanf("%d", n);
    if (*n > SIZE) {
        return 0;
    }
    for (int *p = a; p - a < *n; ++p) {
        scanf("%d", p);
    }
    scanf("%d", shift);
    char c;
    if ((c = getchar()) != '\n') {
        return 0;
    } else {
        return 1;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}

void cycle_shift(int *a, int n, int shift) {
    if (shift > 0) {
        for (int i = 0; i < shift; ++i) {
            int temp = a[0];
            for (int j = 1; j < n; ++j) {
                a[j - 1] = a[j];
            }
            a[n - 1] = temp;
        }
    } else if (shift < 0) {
        shift *= -1;
        for (int i = 0; i < shift; ++i) {
            int temp = a[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                a[j + 1] = a[j];
            }
            a[0] = temp;
        }
    }
}