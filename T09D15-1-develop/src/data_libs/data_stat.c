#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max = -9999.0;
    for (int i = 0; i < n; ++i) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
double min(double *data, int n) {
    double min = 9999.0;
    for (int i = 0; i < n; ++i) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
double mean(double *data, int n) {
    double mean = 0.0;
    for (int i = 0; i < n; ++i) {
        mean += data[i];
    }
    return mean / n;
}
double variance(double *data, int n) {
    double v = 0.0;
    for (int i = 0; i < n; ++i) {
        v += pow((i - mean(data, n)), 2);
    }
    return v / n;
}