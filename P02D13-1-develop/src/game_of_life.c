#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 25  // Высота
#define M 80  // Ширина
#define DEAD '0'
#define HEALTH '1'
#define CELL 'o'
#define EMPTY ' '
#define NEW_LINE '\n'

void change_the_state_of_cell(int array[N][M], int *end_game);
void printGrid(int array[N][M]);
int countNeighbors(int array[N][M], int x, int y);
void updateGrid(int array[N][M], int *end_game);
void readFromFile(int array[N][M], int *ssucces_input);

int main(int argc, char **argv) {
    if (argc == 2) {
        int speed;
        if ((speed = atoi(argv[1])) && speed > 0) {
            int array[N][M] = {0};
            int succes_input = 1;

            readFromFile(array, &succes_input);

            if (succes_input) {
                int end_game = 1;
                while (end_game) {
                    printGrid(array);
                    updateGrid(array, &end_game);
                    sleep(1);
                }
            } else {
                printf("Error input\n");
            }
        } else {
            printf("Error time\n");
        }
    } else {
        printf("Error args\n");
    }

    return (0);
}

void printGrid(int array[N][M]) {
    printf("\033[H\033[J");  // Очистка терминала от всех символов
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (array[i][j] == 1) {
                putchar(CELL);
            } else {
                putchar(EMPTY);
            }
        }
        putchar(NEW_LINE);
    }
}

int countNeighbors(int array[N][M], int x, int y) {
    int neighbors = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int newX = (x + i + N) % N;
            int newY = (y + j + M) % M;

            if (array[newX][newY] == 1 || array[newX][newY] == 3) neighbors++;
        }
    }
    return neighbors;
}

void updateGrid(int array[N][M], int *end_game) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int neighbors = countNeighbors(array, i, j);

            if (array[i][j] == 0) {
                if (neighbors == 3) {
                    array[i][j] = 2;
                }
            } else {
                if (neighbors < 2 || neighbors > 3) {
                    array[i][j] = 3;
                }
            }
        }
    }
    *end_game = 0;
    change_the_state_of_cell(array, end_game);
}

void change_the_state_of_cell(int array[N][M], int *end_game) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (array[i][j] == 2 || array[i][j] == 1) {
                array[i][j] = 1;
                *end_game = 1;

            } else if (array[i][j] == 3) {
                array[i][j] = 0;
            }
        }
    }
}

void readFromFile(int array[N][M], int *succes_input) {
    char ch;
    int res;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res = scanf("%c", &ch);
            if (res) {
                if (ch == DEAD) {
                    array[i][j] = 0;
                } else if (ch == HEALTH) {
                    array[i][j] = 1;
                } else {
                    *succes_input = 0;
                    break;
                }
            } else {
                *succes_input = 0;
                break;
            }
        }
        getchar();
    }
}
