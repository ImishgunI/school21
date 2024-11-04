#include "draw.h"

#include <stdio.h>
#include <math.h> // Для округления и константы M_PI

#define HEIGTH 25           // Высота экрана
#define WIDTH 80            // Ширина экрана
#define STAR '*'            // Символ для графика
#define POINT '.'           // Пустое пространство
#define MIN_VALUE -1.0      // Минимальное значение по y
#define MAX_VALUE 1.0       // Максимальное значение по y
#define X_RANGE (4 * M_PI)  // Диапазон значений x от 0 до 4π

void draw_graph(double* values, int num_values) {
    for (int y = HEIGTH - 1; y >= 0; --y) {    
        for (int x = 0; x < WIDTH; ++x) {      
            if (x < num_values) {
                double scaled_value = (values[x] - MIN_VALUE) / (MAX_VALUE - MIN_VALUE) * (HEIGTH - 1);
                int y_position = HEIGTH / 2 - (int)round((values[x] - MIN_VALUE) / (MAX_VALUE - MIN_VALUE) * (HEIGTH / 2 - 1));

                int x_position = (int)((double)x / (num_values - 1) * (WIDTH - 1));

                if (y == 0) {
                    printf("Debug: x=%d, x_position=%d, values[x]=%f, scaled_value=%f, y_position=%d\n", 
                           x, x_position, values[x], scaled_value, y_position);
                }

                if (y == y_position && x == x_position) {
                    printf("%c", STAR); // Рисуем звезду
                } else {
                    printf("%c", POINT); // Пустое пространство
                }
            } else {
                printf("%c", POINT); // Если нет значения, ставим пустое пространство
            }
        }
        printf("\n"); // Переход на следующую строку
    }
}

