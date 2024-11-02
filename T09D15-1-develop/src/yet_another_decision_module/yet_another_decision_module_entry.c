#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
    double *data = NULL;
    int n;
    if (length(&n) != 1) {
        printf("Error input");
        return 1;
    }
    data = calloc(n, sizeof(double));
    if (data == NULL) {
        printf("Memory wasn't got");
        return 1;
    }
    input(data, n);
    int result = make_decision(data, n);
    if (result)
        printf("YES");
    else
        printf("NO");
    free(data);
    return 0;
}
