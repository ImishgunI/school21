#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n > NMAX) {
        return 0;
    }
    for (int *p = a; p - a < *n; ++p) {
        scanf("%d", p);
    }
    char c;
    if ((c = getchar()) != '\n') {
        return 0;
    } else {
        return 1;
    }
}

void output(int *a, int n) {
    // NOTHING
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        }
        if (i + 1 == n) {
            printf("%d", a[i]);
        }
    }
}

void squaring(int *a, int n) {
    // NOTHING
    for (int i = 0; i < n; ++i) {
        a[i] *= a[i];
    }
}
