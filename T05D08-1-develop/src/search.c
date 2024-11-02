/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>

#define SIZE 10

int input(int *a, int *n);
int find_number(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, array[SIZE];
    if (input(array, &n) == 0) {
        printf("n/a");
    } else {
        int number = find_number(array, n);
        if (find_number(array, n) == 0) {
            printf("0");
        } else {
            printf("%d", number);
        }
    }
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n > SIZE) {
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

double mean(int *a, int n) {
    double m = 0.0;
    for (int i = 0; i < n; ++i) {
        m += a[i];
    }
    return m / n;
}

double variance(int *a, int n) {
    double dispersion = 0.0;
    for (int i = 1; i <= n; ++i) {
        dispersion += pow((i - mean(a, n)), 2);
    }
    return dispersion / n;
}

int find_number(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0 && a[i] >= mean(a, n) && a[i] <= mean(a, n) + 3 * sqrt(variance(a, n)) &&
            a[i] != 0) {
            return a[i];
        }
    }
    return 0;
}
