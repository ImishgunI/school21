#include "draw.h"

#include <math.h>  // Для округления и константы M_PI
#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80
#define STAR '*'
#define POINT '.'
#define MIN_VALUE -1.0
#define MAX_VALUE 1.0
#define M_PI 3.14159265358979323846

void draw_graph(double* values, int num_values) {
    char field[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = '.';
        }
    }
    int step = WIDTH / num_values;

    for (int i = 0; i < num_values; i++) {
        int x = i * step;
        int y = (int)round((1 - values[i]) * 12);

        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            field[y][x] = '*';
        }
    }

    // Вывод графика на экран
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(field[i][j]);
        }
        putchar('\n');
    }
}
