#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = -2147483648;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = 2147483647;
    for (int i = 0; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}