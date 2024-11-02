#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double* data, int n) {
    for (int i = 0; i < n; ++i) {
        if (scanf("%lf", &data[i]) != 1) {
            printf("n/a");
            break;
        }
    }
}

void output(double* data, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%.2lf ", data[i]);
        } else {
            printf("%.2lf", data[i]);
        }
    }
}

int length(int* n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        return 0;
    }
    return 1;
}
