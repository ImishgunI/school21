#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n;
    if (length(&n) != 1) {
        printf("Error input");
        return 1;
    }
    // Don`t forget to allocate memory !
    data = calloc(n, sizeof(double));
    if (data == NULL) {
        printf("Memory wasn't got");
        return 1;
    }
    input(data, n);
    int result = normalization(data, n);
    if (result != 0)
        output(data, n);
    else
        printf("ERROR");
    free(data);
    return 0;
}
